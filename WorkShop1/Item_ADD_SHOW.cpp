//Item_Add_Show.cpp

#include "Header.h"


void addNewPhysicalGame(sql::Connection* con)
{

    system("cls");  // Clear the console screen
    cout << "+------------------------------------------------+" << endl;
    cout << "|              Adding a new Physical Game        |" << endl;
    cout << "+------------------------------------------------+" << endl;
    

    // Get user input for each attribute
    int gameslistID;
    string itemName, itemCondition, itemDate;
    int itemQuantity;
    double itemPrice;

    cout << "\n| Physical Game ID        | : ";
    cin >> gameslistID;

    cout << "\n| Item Name               | : ";
    cin.ignore(); // Ignore any previous newline character in the buffer
    getline(cin, itemName);

    cout << "\n| Item Quantity           | : ";
    cin >> itemQuantity;

    cout << "\n| Item Condition          | : ";
    cin.ignore();
    getline(cin, itemCondition);

    cout << "\n| Item Price              | : ";
    cin >> itemPrice;

    cout << "\n| Item Date (YYYY-MM-DD)  | : ";
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
    
    cout << "+------------------------------------------------+" << endl;
    cout << "|              Adding a new Device               |" << endl;
    cout << "+------------------------------------------------+" << endl;

    // Get user input for each attribute
    int deviceslistID;
    string itemName, itemCondition, itemDate;
    int itemQuantity;
    double itemPrice;

    cout << "\n| Device ID               | : ";
    cin >> deviceslistID;

    cout << "\n| Item Name               | : ";
    cin.ignore(); // Ignore any previous newline character in the buffer
    getline(cin, itemName);

    cout << "\n| Item Quantity           | : ";
    cin >> itemQuantity;

    cout << "\n| Item Condition          | : ";
    cin.ignore();
    getline(cin, itemCondition);

    cout << "\n| Item Price              | : ";
    cin >> itemPrice;

    cout << "\n| Item Date (YYYY-MM-DD)  | : ";
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

        cout << "Physical Games" << endl;
        cout << "\n" << left << setw(14) << "Games ID" << setw(35) << "Item Name" << setw(18) << "Item Quantity"
            << setw(18) << "Item Condition" << setw(18) << "Item Price" << setw(18) << "Item Date" << endl;

        while (res->next())
        {
            cout << left << setw(14) << res->getInt("Games_List_ID") << setw(35) << res->getString("Item_Name")
                << setw(18) << res->getInt("Item_Quantity") << setw(18) << res->getString("Item_Condition")
                << setw(18) << res->getDouble("Item_Price") << setw(18) << res->getString("Item_Date") << endl;
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
            enterCustomer(con);
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

        cout << "Devices" << endl;
        cout <<"\n"<< left << setw(14) << "Devices ID" << setw(35) << "Item Name" << setw(18) << "Item Quantity"
            << setw(18) << "Item Condition" << setw(18) << "Item Price" << setw(18) << "Item Date" << endl;

        while (res->next())
        {
            cout << left << setw(14) << res->getInt("Devices_List_ID") << setw(35) << res->getString("Item_Name")
                << setw(18) << res->getInt("Item_Quantity") << setw(18) << res->getString("Item_Condition")
                << setw(18) << res->getDouble("Item_Price") << setw(18) << res->getString("Item_Date") << endl;
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
            enterCustomer(con);
        }
    }
    catch (sql::SQLException e)
    {
        cout << "Error fetching Devices. Error message: " << e.what() << endl;
    }
}