//Item_Add_Show.cpp

#include "Header.h"


void addNewPhysicalGame(sql::Connection* con)
{
    cout << "\nAdding a new Physical Game:" << endl;

    // Get user input for each attribute
    int gameslistID;
    string itemName, itemCondition, itemDate;
    int itemQuantity;
    double itemPrice;

    cout << "\nPhysical Game ID: ";
    cin >> gameslistID;

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

    try
    {
        con->setSchema("database");

        // Insert the new Physical Game into the database
        sql::PreparedStatement* pstmt = con->prepareStatement(
            "INSERT INTO PhysicalGames (Games_list_ID, Item_Name, Item_Quantity, Item_Condition, Item_Price, Item_Date) "
            "VALUES (?, ?, ?, ?, ?, ?)");

        pstmt->setInt(1, gameslistID);
        pstmt->setString(2, itemName);
        pstmt->setInt(3, itemQuantity);
        pstmt->setString(4, itemCondition);
        pstmt->setDouble(5, itemPrice);
        pstmt->setString(6, itemDate);

        pstmt->execute();
        delete pstmt;

        cout << "Physical Game added successfully!" << endl;
    }
    catch (sql::SQLException e)
    {
        cout << "Error adding Physical Game. Error message: " << e.what() << endl;
    }
}

void addNewDevice(sql::Connection* con)
{
    cout << "\nAdding a new Device:" << endl;

    // Get user input for each attribute
    int deviceslistID;
    string itemName, itemCondition, itemDate;
    int itemQuantity;
    double itemPrice;

    cout << "\n Device ID: ";
    cin >> deviceslistID;

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

    try
    {
        con->setSchema("database");

        // Insert the new Device into the database
        sql::PreparedStatement* pstmt = con->prepareStatement(
            "INSERT INTO Devices (Devices_list_ID, Item_Name, Item_Quantity, Item_Condition, Item_Price, Item_Date) "
            "VALUES (?, ?, ?, ?, ?, ?)");

        pstmt->setInt(1, deviceslistID);
        pstmt->setString(2, itemName);
        pstmt->setInt(3, itemQuantity);
        pstmt->setString(4, itemCondition);
        pstmt->setDouble(5, itemPrice);
        pstmt->setString(6, itemDate);

        pstmt->execute();
        delete pstmt;

        cout << "Device added successfully!" << endl;
    }
    catch (sql::SQLException e)
    {
        cout << "Error adding Device. Error message: " << e.what() << endl;
    }
}

void showPhysicalGames(sql::Connection* con)
{
    try
    {
        con->setSchema("database");

        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM PhysicalGames");

        cout << "Physical Games:" << endl;
        cout << left << setw(8) << "Games_List_ID" << setw(20) << "Item_Name" << setw(15) << "Item_Quantity"
            << setw(15) << "Item_Condition" << setw(15) << "Item_Price" << setw(15) << "Item_Date" << endl;

        while (res->next())
        {
            cout << left << setw(8) << res->getInt("Games_List_ID") << setw(20) << res->getString("Item_Name")
                << setw(15) << res->getInt("Item_Quantity") << setw(15) << res->getString("Item_Condition")
                << setw(15) << res->getDouble("Item_Price") << setw(15) << res->getString("Item_Date") << endl;
        }

        delete res;
        delete stmt;

        // Ask the customer if they want to order
        cout << "\nDo you want to order? (y/n): ";
        char orderChoice;
        cin >> orderChoice;

        if (orderChoice == 'y' || orderChoice == 'Y')
        {
            // Call the function to order new items
            orderNewGames(con);
        }
        else
        {
            // Customer chose not to order, you can go back to the customer menu or perform other actions.
            // Add your code here.
            processCustomer(con);
        }
    }
    catch (sql::SQLException e)
    {
        cout << "Error fetching Physical Games. Error message: " << e.what() << endl;
    }
}


void showDevices(sql::Connection* con)
{
    try
    {
        con->setSchema("database");

        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM Devices");

        cout << "Devices:" << endl;
        cout << left << setw(8) << "Devices_list_ID" << setw(20) << "Item_Name" << setw(15) << "Item_Quantity"
            << setw(15) << "Item_Condition" << setw(15) << "Item_Price" << setw(15) << "Item_Date" << endl;

        while (res->next())
        {
            cout << left << setw(8) << res->getInt("Devices_List_ID") << setw(20) << res->getString("Item_Name")
                << setw(15) << res->getInt("Item_Quantity") << setw(15) << res->getString("Item_Condition")
                << setw(15) << res->getDouble("Item_Price") << setw(15) << res->getString("Item_Date") << endl;
        }

        delete res;
        delete stmt;

        cout << "\nDo you want to order? (y/n): ";
        char orderChoice;
        cin >> orderChoice;


        if (orderChoice == 'y' || orderChoice == 'Y')
        {
            // Call the function to order new items
            orderNewDevice(con);
        }
        else
        {
            // Customer chose not to order, you can go back to the customer menu or perform other actions.
            // Add your code here.
            processCustomer(con);
        }
    }
    catch (sql::SQLException e)
    {
        cout << "Error fetching Devices. Error message: " << e.what() << endl;
    }
}