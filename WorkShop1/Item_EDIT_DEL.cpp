#include "Header.h"
void editPhysicalGame(sql::Connection* con)
{
    cout << "\nEditing a Physical Game:" << endl;

    int gameslistID;
    cout << "\nEnter Physical ID of the Physical Game to edit: ";
    cin >> gameslistID;

    try
    {
        con->setSchema("database");

        // Retrieve the details of the Physical Game based on Games_List_ID
        sql::PreparedStatement* pstmtSelect = con->prepareStatement("SELECT * FROM PhysicalGames WHERE Games_List_ID = ?");
        pstmtSelect->setInt(1, gameslistID);

        sql::ResultSet* res = pstmtSelect->executeQuery();

        // Check if the Physical Game with the provided Games_List_ID exists
        if (res->next())
        {
            // Display the current details
            cout << "\nCurrent details:" << endl;
            cout << "Games_List_ID: " << res->getInt("Games_List_ID") << endl;
            cout << "Item_Name: " << res->getString("Item_Name") << endl;
            cout << "Item_Quantity: " << res->getInt("Item_Quantity") << endl;
            cout << "Item_Condition: " << res->getString("Item_Condition") << endl;
            cout << "Item_Price: " << res->getDouble("Item_Price") << endl;
            cout << "Item_Date: " << res->getString("Item_Date") << endl;

            // Prompt for attribute to edit
            cout << "\nEnter attribute to edit (1. Name, 2. Quantity, 3. Condition, 4. Price, 5. Date): ";
            int attributeChoice;
            cin >> attributeChoice;

            // Get updated value from the staff based on the chosen attribute
            string updatedValue;
            cout << "Enter updated value: ";
            cin.ignore(); // Ignore any previous newline character in the buffer
            getline(cin, updatedValue);

            // Update the Physical Game in the database based on the chosen attribute
            sql::PreparedStatement* pstmtUpdate = nullptr;

            switch (attributeChoice)
            {
            case 1:
                pstmtUpdate = con->prepareStatement("UPDATE PhysicalGames SET Item_Name = ? WHERE Games_List_ID = ?");
                break;
            case 2:
                pstmtUpdate = con->prepareStatement("UPDATE PhysicalGames SET Item_Quantity = ? WHERE Games_List_ID = ?");
                break;
            case 3:
                pstmtUpdate = con->prepareStatement("UPDATE PhysicalGames SET Item_Condition = ? WHERE Games_List_ID = ?");
                break;
            case 4:
                pstmtUpdate = con->prepareStatement("UPDATE PhysicalGames SET Item_Price = ? WHERE Games_List_ID = ?");
                break;
            case 5:
                pstmtUpdate = con->prepareStatement("UPDATE PhysicalGames SET Item_Date = ? WHERE Games_List_ID = ?");
                break;
            default:
                cout << "Invalid attribute choice." << endl;
                return;
            }

            pstmtUpdate->setString(1, updatedValue);
            pstmtUpdate->setInt(2, gameslistID);

            pstmtUpdate->execute();
            delete pstmtUpdate;

            cout << "Physical Game attribute updated successfully!" << endl;
        }
        else
        {
            cout << "Physical Game with Games_List_ID " << gameslistID << " does not exist." << endl;
        }

        delete res;
        delete pstmtSelect;
    }
    catch (sql::SQLException e)
    {
        cout << "Error editing Physical Game. Error message: " << e.what() << endl;
    }
}

void editDevice(sql::Connection* con)
{
    cout << "\nEditing a Device:" << endl;

    int deviceslistID;
    cout << "Enter Device ID of the Device to edit: ";
    cin >> deviceslistID;

    try
    {
        con->setSchema("database");

        // Retrieve the details of the Device based on Devices_List_ID
        sql::PreparedStatement* pstmtSelect = con->prepareStatement("SELECT * FROM Devices WHERE Devices_List_ID = ?");
        pstmtSelect->setInt(1, deviceslistID);

        sql::ResultSet* res = pstmtSelect->executeQuery();

        // Check if the Device with the provided Devices_List_ID exists
        if (res->next())
        {
            // Display the current details
            cout << "\nCurrent details:" << endl;
            cout << "Devices_List_ID: " << res->getInt("Devices_List_ID") << endl;
            cout << "Item_Name: " << res->getString("Item_Name") << endl;
            cout << "Item_Quantity: " << res->getInt("Item_Quantity") << endl;
            cout << "Item_Condition: " << res->getString("Item_Condition") << endl;
            cout << "Item_Price: " << res->getDouble("Item_Price") << endl;
            cout << "Item_Date: " << res->getString("Item_Date") << endl;

            // Prompt for attribute to edit
            cout << "\nEnter attribute to edit (1. Name, 2. Quantity, 3. Condition, 4. Price, 5. Date): ";
            int attributeChoice;
            cin >> attributeChoice;

            // Get updated value from the staff based on the chosen attribute
            string updatedValue;
            cout << "Enter updated value: ";
            cin.ignore(); // Ignore any previous newline character in the buffer
            getline(cin, updatedValue);

            // Update the Device in the database based on the chosen attribute
            sql::PreparedStatement* pstmtUpdate = nullptr;

            switch (attributeChoice)
            {
            case 1:
                pstmtUpdate = con->prepareStatement("UPDATE Devices SET Item_Name = ? WHERE Devices_List_ID = ?");
                break;
            case 2:
                pstmtUpdate = con->prepareStatement("UPDATE Devices SET Item_Quantity = ? WHERE Devices_List_ID = ?");
                break;
            case 3:
                pstmtUpdate = con->prepareStatement("UPDATE Devices SET Item_Condition = ? WHERE Devices_List_ID = ?");
                break;
            case 4:
                pstmtUpdate = con->prepareStatement("UPDATE Devices SET Item_Price = ? WHERE Devices_List_ID = ?");
                break;
            case 5:
                pstmtUpdate = con->prepareStatement("UPDATE Devices SET Item_Date = ? WHERE Devices_List_ID = ?");
                break;
            default:
                cout << "Invalid attribute choice." << endl;
                return;
            }

            pstmtUpdate->setString(1, updatedValue);
            pstmtUpdate->setInt(2, deviceslistID);

            pstmtUpdate->execute();
            delete pstmtUpdate;

            cout << "Device attribute updated successfully!" << endl;
        }
        else
        {
            cout << "Device with Devices_List_ID " << deviceslistID << " does not exist." << endl;
        }

        delete res;
        delete pstmtSelect;
    }
    catch (sql::SQLException e)
    {
        cout << "Error editing Device. Error message: " << e.what() << endl;
    }
}

void editItem(sql::Connection* con)
{
    char itemTypeChoice;
    cout << "Choose the item type to edit:" << endl;
    cout << "1. Physical Game" << endl;
    cout << "2. Device" << endl;
    cout << "Enter your choice (1 or 2): ";
    itemTypeChoice = _getch() - '0';

    switch (itemTypeChoice)
    {
    case 1:
        editPhysicalGame(con);
        break;
    case 2:
        editDevice(con);
        break;
    default:
        cout << "Invalid item type choice." << endl;
        break;
    }
}

void deletePhysicalGame(sql::Connection* con)
{
    cout << "\nDeleting a Physical Game:" << endl;

    // Display the current Physical Games
    showPhysicalGames(con);

    int gameslistID;
    cout << "Enter List ID of the Physical Game to delete (enter -1 to cancel): ";
    cin >> gameslistID;

    if (cin.fail())
    {
        // Invalid input, clear the cin buffer and ignore the entered value
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Returning to the staff menu." << endl;
        return;
    }

    if (gameslistID == -1)
    {
        cout << "Returning to the staff menu." << endl;
        return;
    }


    try
    {
        con->setSchema("database");

        // Check if the Physical Game with the provided List_ID exists
        sql::PreparedStatement* pstmtSelect = con->prepareStatement("SELECT * FROM PhysicalGames WHERE Games_List_ID = ?");
        pstmtSelect->setInt(1, gameslistID);

        sql::ResultSet* res = pstmtSelect->executeQuery();

        if (res->next())
        {
            // Physical Game found, confirm deletion
            cout << "\nAre you sure you want to delete the following Physical Game?" << endl;
            cout << "Games_List_ID: " << res->getInt("Games_List_ID") << endl;
            cout << "Item_Name: " << res->getString("Item_Name") << endl;
            cout << "Item_Quantity: " << res->getInt("Item_Quantity") << endl;
            cout << "Item_Condition: " << res->getString("Item_Condition") << endl;
            cout << "Item_Price: " << res->getDouble("Item_Price") << endl;
            cout << "Item_Date: " << res->getString("Item_Date") << endl;

            char confirmDelete;
            cout << "Confirm deletion? (y/n): ";
            cin >> confirmDelete;

            if (confirmDelete == 'y' || confirmDelete == 'Y')
            {
                // Delete the Physical Game from the database
                sql::PreparedStatement* pstmtDelete = con->prepareStatement("DELETE FROM PhysicalGames WHERE Games_List_ID = ?");
                pstmtDelete->setInt(1, gameslistID);
                pstmtDelete->execute();
                delete pstmtDelete;

                cout << "Physical Game deleted successfully!" << endl;
            }
            else
            {
                cout << "Deletion canceled. Returning to the staff menu." << endl;
            }
        }
        else
        {
            cout << "Physical Game with Games_List_ID " << gameslistID << " does not exist." << endl;
        }

        delete res;
        delete pstmtSelect;
    }
    catch (sql::SQLException e)
    {
        cout << "Error deleting Physical Game. Error message: " << e.what() << endl;
    }
}

void deleteDevice(sql::Connection* con)
{
    cout << "\nDeleting a Device:" << endl;

    // Display the current Devices
    showDevices(con);

    int deviceslistID;
    cout << "Enter List ID of the Device to delete (or 'x' to cancel): ";
    cin >> deviceslistID;

    if (cin.fail())
    {
        // Invalid input, clear the cin buffer and ignore the entered value
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Returning to the staff menu." << endl;
        return;
    }

    if (deviceslistID == 'x')
    {
        cout << "Returning to the staff menu." << endl;
        return;
    }

    try
    {
        con->setSchema("database");

        // Check if the Device with the provided List_ID exists
        sql::PreparedStatement* pstmtSelect = con->prepareStatement("SELECT * FROM Devices WHERE Devices_List_ID = ?");
        pstmtSelect->setInt(1, deviceslistID);

        sql::ResultSet* res = pstmtSelect->executeQuery();

        if (res->next())
        {
            // Device found, confirm deletion
            cout << "\nAre you sure you want to delete the following Device?" << endl;
            cout << "Devices_List_ID : " << res->getInt("Devices_List_ID ") << endl;
            cout << "Item_Name: " << res->getString("Item_Name") << endl;
            cout << "Item_Quantity: " << res->getInt("Item_Quantity") << endl;
            cout << "Item_Condition: " << res->getString("Item_Condition") << endl;
            cout << "Item_Price: " << res->getDouble("Item_Price") << endl;
            cout << "Item_Date: " << res->getString("Item_Date") << endl;

            char confirmDelete;
            cout << "Confirm deletion? (y/n): ";
            cin >> confirmDelete;

            if (confirmDelete == 'y' || confirmDelete == 'Y')
            {
                // Delete the Device from the database
                sql::PreparedStatement* pstmtDelete = con->prepareStatement("DELETE FROM Devices WHERE Devices_List_ID = ?");
                pstmtDelete->setInt(1, deviceslistID);
                pstmtDelete->execute();
                delete pstmtDelete;

                cout << "Device deleted successfully!" << endl;
            }
            else
            {
                cout << "Deletion canceled. Returning to the staff menu." << endl;
            }
        }
        else
        {
            cout << "Device with Devices_List_ID " << deviceslistID << " does not exist." << endl;
        }

        delete res;
        delete pstmtSelect;
    }
    catch (sql::SQLException e)
    {
        cout << "Error deleting Device. Error message: " << e.what() << endl;
    }
}

void displayAvailableItemsWithCondition(sql::Connection* con, const string& condition, bool includeCondition)
{
}

