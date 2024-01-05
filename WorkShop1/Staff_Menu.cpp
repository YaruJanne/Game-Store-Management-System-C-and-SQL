#include"Header.h"

void staffMenu(sql::Connection* con)
{
    int staffChoice;

    do
    {
        cout << "\nStaff Record:" << endl;
        cout << "1. Add new staff record" << endl;
        cout << "2. Edit Staff details" << endl;
        cout << "3. Delete Staff record" << endl;
        cout << "4. Show staff record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> staffChoice;

        switch (staffChoice)
        {
        case 1:
            addStaffRecord(con);
            break;
        case 2:
            editStaffDetails(con);
            break;
        case 3:
            deleteStaffRecord(con);
            break;
        case 4:
            showStaffRecord(con);
            break;
        case 5:
            cout << "Exiting Staff Menu." << endl;
            return;  // Exit the staffMenu function
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            break;
        }

        // Check if the user pressed 'x' to return to the staff menu
        if (staffChoice != 5)
        {
            char returnToMenu;
            cout << "Press 'x' to return to the Staff Menu: ";
            cin >> returnToMenu;

            if (returnToMenu != 'x')
            {
                cout << "Invalid input. Returning to the Staff Menu." << endl;
                staffChoice = 0;  // Set staffChoice to an invalid value to loop back
            }
        }
    } while (staffChoice != 5);

    cout << "Staff functionality coming soon!" << endl;
}


void addStaffRecord(sql::Connection* con)
{
    cout << "\nAdding a new Staff record:" << endl;

    // Get user input for each attribute
    int staffID;
    string staffName, staffRole, staffEmail, staffPassword;

    cout << "\nStaff ID: ";
    cin >> staffID;

    cout << "Staff Name: ";
    cin.ignore();
    getline(cin, staffName);

    cout << "Staff Role: ";
    cin.ignore();
    getline(cin, staffRole);

    cout << "Staff Email: ";
    cin.ignore();
    getline(cin, staffEmail);

    cout << "Staff Password: ";
    cin.ignore();
    getline(cin, staffPassword);

    try
    {
        con->setSchema("database");

        // Insert the new Staff record into the database
        sql::PreparedStatement* pstmt = con->prepareStatement(
            "INSERT INTO Staff (Staff_ID, Staff_Name, Staff_Role, Staff_Email, Staff_Password) "
            "VALUES (?, ?, ?, ?, ?)");

        pstmt->setInt(1, staffID);
        pstmt->setString(2, staffName);
        pstmt->setString(3, staffRole);
        pstmt->setString(4, staffEmail);
        pstmt->setString(5, staffPassword);

        pstmt->execute();
        delete pstmt;

        cout << "Staff record added successfully!" << endl;
    }
    catch (sql::SQLException e)
    {
        cout << "Error adding Staff record. Error message: " << e.what() << endl;
    }
}

void editStaffDetails(sql::Connection* con)
{
    int staffID;
    cout << "Enter Staff ID to edit details: ";
    cin >> staffID;

    try
    {
        con->setSchema("database");

        // Check if the Staff record with the provided Staff_ID exists
        sql::PreparedStatement* pstmtSelect = con->prepareStatement("SELECT * FROM Staff WHERE Staff_ID = ?");
        pstmtSelect->setInt(1, staffID);

        sql::ResultSet* res = pstmtSelect->executeQuery();

        if (res->next())
        {
            // Staff record found, allow editing
            cout << "\nEditing Staff record with Staff_ID: " << staffID << endl;

            // Add your code to get user input for updated details and perform the update

            cout << "Staff record updated successfully!" << endl;
        }
        else
        {
            cout << "Staff record with Staff_ID " << staffID << " does not exist." << endl;
        }

        delete res;
        delete pstmtSelect;
    }
    catch (sql::SQLException e)
    {
        cout << "Error editing Staff record. Error message: " << e.what() << endl;
    }
}

void deleteStaffRecord(sql::Connection* con)
{
    int staffID;
    cout << "\nDeleting a Staff record:" << endl;
    cout << "Enter Staff ID to delete (or 'x' to cancel): ";
    cin >> staffID;

    if (staffID == 'x')
    {
        cout << "Returning to the staff menu." << endl;
        return;
    }

    try
    {
        con->setSchema("database");

        // Check if the Staff record with the provided Staff_ID exists
        sql::PreparedStatement* pstmtSelect = con->prepareStatement("SELECT * FROM Staff WHERE Staff_ID = ?");
        pstmtSelect->setInt(1, staffID);

        sql::ResultSet* res = pstmtSelect->executeQuery();

        if (res->next())
        {
            // Staff record found, confirm deletion
            cout << "\nAre you sure you want to delete the following Staff record?" << endl;
            cout << "Staff_ID: " << res->getInt("Staff_ID") << endl;
            cout << "Staff_Name: " << res->getString("Staff_Name") << endl;
            cout << "Staff_Role: " << res->getString("Staff_Role") << endl;
            cout << "Staff_Email: " << res->getString("Staff_Email") << endl;

            char confirmDelete;
            cout << "Confirm deletion? (y/n): ";
            cin >> confirmDelete;

            if (confirmDelete == 'y' || confirmDelete == 'Y')
            {
                // Delete the Staff record from the database
                sql::PreparedStatement* pstmtDelete = con->prepareStatement("DELETE FROM Staff WHERE Staff_ID = ?");
                pstmtDelete->setInt(1, staffID);
                pstmtDelete->execute();
                delete pstmtDelete;

                cout << "Staff record deleted successfully!" << endl;
            }
            else
            {
                cout << "Deletion canceled. Returning to the staff menu." << endl;
            }
        }
        else
        {
            cout << "Staff record with Staff_ID " << staffID << " does not exist." << endl;
        }

        delete res;
        delete pstmtSelect;
    }
    catch (sql::SQLException e)
    {
        cout << "Error deleting Staff record. Error message: " << e.what() << endl;
    }
}

void showStaffRecord(sql::Connection* con)
{
    try
    {
        con->setSchema("database");

        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM Staff");

        cout << "Staff Records:" << endl;
        cout << left << setw(8) << "Staff_ID" << setw(20) << "Staff_Name" << setw(15) << "Staff_Role"
            << setw(30) << "Staff_Email" << setw(20) << "Staff_Password" << endl;

        while (res->next())
        {
            cout << left << setw(8) << res->getInt("Staff_ID") << setw(20) << res->getString("Staff_Name")
                << setw(15) << res->getString("Staff_Role") << setw(30) << res->getString("Staff_Email")
                << setw(20) << res->getString("Staff_Password") << endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException e)
    {
        cout << "Error fetching Staff records. Error message: " << e.what() << endl;
    }
}