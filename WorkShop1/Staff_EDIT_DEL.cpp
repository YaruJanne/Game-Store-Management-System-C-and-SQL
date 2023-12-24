#include "Header.h"
void editPhysicalGame(sql::Connection* con)
{
    cout << "\nEditing a Physical Game:" << endl;

    int listID;
    cout << "\nEnter List ID of the Physical Game to edit: ";
    cin >> listID;

    try
    {
        con->setSchema("database");

        // Retrieve the details of the Physical Game based on List_ID
        sql::PreparedStatement* pstmtSelect = con->prepareStatement("SELECT * FROM PhysicalGames WHERE List_ID = ?");
        pstmtSelect->setInt(1, listID);

        sql::ResultSet* res = pstmtSelect->executeQuery();

        // Check if the Physical Game with the provided List_ID exists
        if (res->next())
        {
            // Display the current details
            cout << "\nCurrent details:" << endl;
            cout << "List_ID: " << res->getInt("List_ID") << endl;
            cout << "Item_Name: " << res->getString("Item_Name") << endl;
            cout << "Item_Quantity: " << res->getInt("Item_Quantity") << endl;
            cout << "Item_Condition: " << res->getString("Item_Condition") << endl;
            cout << "Item_Price: " << res->getDouble("Item_Price") << endl;
            cout << "Item_Date: " << res->getString("Item_Date") << endl;

            // Get updated values from the staff
            string itemName, itemCondition, itemDate;
            int itemQuantity;
            double itemPrice;

            cout << "\nEnter updated details:" << endl;
            cout << "Item Name: ";
            cin.ignore(); // Ignore any previous newline character in the buffer
            getline(cin, itemName);

            cout << "Item Quantity: ";
            cin >> itemQuantity;

            cout << "Item Condition: ";
            cin.ignore();
            getline(cin, itemCondition);

            cout << "Item Price: ";
            cin >> itemPrice;

            cout << "Item Date (YYYY-MM-DD): ";
            cin.ignore();
            getline(cin, itemDate);

            // Update the Physical Game in the database
            sql::PreparedStatement* pstmtUpdate = con->prepareStatement(
                "UPDATE PhysicalGames SET Item_Name = ?, Item_Quantity = ?, Item_Condition = ?, "
                "Item_Price = ?, Item_Date = ? WHERE List_ID = ?");

            pstmtUpdate->setString(1, itemName);
            pstmtUpdate->setInt(2, itemQuantity);
            pstmtUpdate->setString(3, itemCondition);
            pstmtUpdate->setDouble(4, itemPrice);
            pstmtUpdate->setString(5, itemDate);
            pstmtUpdate->setInt(6, listID);

            pstmtUpdate->execute();
            delete pstmtUpdate;

            cout << "Physical Game updated successfully!" << endl;
        }
        else
        {
            cout << "Physical Game with List_ID " << listID << " does not exist." << endl;
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

    int listID;
    cout << "Enter List ID of the Device to edit: ";
    cin >> listID;

    try
    {
        con->setSchema("database");

        // Retrieve the details of the Device based on List_ID
        sql::PreparedStatement* pstmtSelect = con->prepareStatement("SELECT * FROM Devices WHERE List_ID = ?");
        pstmtSelect->setInt(1, listID);

        sql::ResultSet* res = pstmtSelect->executeQuery();

        // Check if the Device with the provided List_ID exists
        if (res->next())
        {
            // Display the current details
            cout << "\nCurrent details:" << endl;
            cout << "List_ID: " << res->getInt("List_ID") << endl;
            cout << "Item_Name: " << res->getString("Item_Name") << endl;
            cout << "Item_Quantity: " << res->getInt("Item_Quantity") << endl;
            cout << "Item_Condition: " << res->getString("Item_Condition") << endl;
            cout << "Item_Price: " << res->getDouble("Item_Price") << endl;
            cout << "Item_Date: " << res->getString("Item_Date") << endl;

            // Get updated values from the staff
            string itemName, itemCondition, itemDate;
            int itemQuantity;
            double itemPrice;

            cout << "\nEnter updated details:" << endl;
            cout << "Item Name: ";
            cin.ignore(); // Ignore any previous newline character in the buffer
            getline(cin, itemName);

            cout << "Item Quantity: ";
            cin >> itemQuantity;

            cout << "Item Condition: ";
            cin.ignore();
            getline(cin, itemCondition);

            cout << "Item Price: ";
            cin >> itemPrice;

            cout << "Item Date (YYYY-MM-DD): ";
            cin.ignore();
            getline(cin, itemDate);

            // Update the Device in the database
            sql::PreparedStatement* pstmtUpdate = con->prepareStatement(
                "UPDATE Devices SET Item_Name = ?, Item_Quantity = ?, Item_Condition = ?, "
                "Item_Price = ?, Item_Date = ? WHERE List_ID = ?");

            pstmtUpdate->setString(1, itemName);
            pstmtUpdate->setInt(2, itemQuantity);
            pstmtUpdate->setString(3, itemCondition);
            pstmtUpdate->setDouble(4, itemPrice);
            pstmtUpdate->setString(5, itemDate);
            pstmtUpdate->setInt(6, listID);

            pstmtUpdate->execute();
            delete pstmtUpdate;

            cout << "Device updated successfully!" << endl;
        }
        else
        {
            cout << "Device with List_ID " << listID << " does not exist." << endl;
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
    int itemTypeChoice;
    cout << "Choose the item type to edit:" << endl;
    cout << "1. Physical Game" << endl;
    cout << "2. Device" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> itemTypeChoice;

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

    int listID;
    cout << "Enter List ID of the Physical Game to delete (or 'x' to cancel): ";
    cin >> listID;

    if (cin.fail())
    {
        // Invalid input, clear the cin buffer and ignore the entered value
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Returning to the staff menu." << endl;
        return;
    }

    if (listID == 'x')
    {
        cout << "Returning to the staff menu." << endl;
        return;
    }

    try
    {
        con->setSchema("database");

        // Check if the Physical Game with the provided List_ID exists
        sql::PreparedStatement* pstmtSelect = con->prepareStatement("SELECT * FROM PhysicalGames WHERE List_ID = ?");
        pstmtSelect->setInt(1, listID);

        sql::ResultSet* res = pstmtSelect->executeQuery();

        if (res->next())
        {
            // Physical Game found, confirm deletion
            cout << "\nAre you sure you want to delete the following Physical Game?" << endl;
            cout << "List_ID: " << res->getInt("List_ID") << endl;
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
                sql::PreparedStatement* pstmtDelete = con->prepareStatement("DELETE FROM PhysicalGames WHERE List_ID = ?");
                pstmtDelete->setInt(1, listID);
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
            cout << "Physical Game with List_ID " << listID << " does not exist." << endl;
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

    int listID;
    cout << "Enter List ID of the Device to delete (or 'x' to cancel): ";
    cin >> listID;

    if (cin.fail())
    {
        // Invalid input, clear the cin buffer and ignore the entered value
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Returning to the staff menu." << endl;
        return;
    }

    if (listID == 'x')
    {
        cout << "Returning to the staff menu." << endl;
        return;
    }

    try
    {
        con->setSchema("database");

        // Check if the Device with the provided List_ID exists
        sql::PreparedStatement* pstmtSelect = con->prepareStatement("SELECT * FROM Devices WHERE List_ID = ?");
        pstmtSelect->setInt(1, listID);

        sql::ResultSet* res = pstmtSelect->executeQuery();

        if (res->next())
        {
            // Device found, confirm deletion
            cout << "\nAre you sure you want to delete the following Device?" << endl;
            cout << "List_ID: " << res->getInt("List_ID") << endl;
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
                sql::PreparedStatement* pstmtDelete = con->prepareStatement("DELETE FROM Devices WHERE List_ID = ?");
                pstmtDelete->setInt(1, listID);
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
            cout << "Device with List_ID " << listID << " does not exist." << endl;
        }

        delete res;
        delete pstmtSelect;
    }
    catch (sql::SQLException e)
    {
        cout << "Error deleting Device. Error message: " << e.what() << endl;
    }
}

