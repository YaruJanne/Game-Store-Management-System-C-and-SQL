//Order.cpp

#include "Header.h"



void orderMenu(sql::Connection* con);

void orderMenu(sql::Connection* con)
{
    char orderChoice;

    do
    {
        cout << "\nOrder Menu:" << endl;
        cout << "1. Order" << endl;
        cout << "2. Show Order" << endl;
        cout << "3. Exit to Customer Menu" << endl;
        cout << "Enter your choice (1, 2, or 3): ";
        orderChoice = _getch() - '0';

        switch (orderChoice)
        {
        case 1:
            orderNewGames(con);
            break;
        case 2:
            // Show existing orders
            // Implement logic to display the purchase record from the database
            // You can create a function for this, e.g., showOrder(con, customerEmail);
            break;
        case 3:
            cout << "Exiting to Customer Menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
            break;
        }

        // Check if the user pressed 'x' to return to the Order menu
        char returnToMenu;
        cout << "Press 'x' to return to the Customer Menu: ";
        cin >> returnToMenu;

        if (returnToMenu != 'x')
        {
            cout << "Invalid input. Returning to the Order menu." << endl;
        }
        else
        {
            cout << "Going back to Customer Menu." << endl;
        }
    } while (orderChoice != 3);  // Repeat the loop until the user chooses to exit
}

// Implement the orderNewItems and showOrder functions as needed

void orderNewGames(sql::Connection* con)
{
    try
    {
        con->setSchema("database");  // Replace 'your_database_name' with your actual database name

        // Prompt the user for order details
        string gamesListIDInput;
        int purQuantity;
        string purName, Cus_Email;

        cout << "Enter Games ID  ";
        cin >> gamesListIDInput;

        // Search for Devices_List_ID in the devices database
        int gamesListID;
        if (gamesListIDInput != "x")
        {
            sql::PreparedStatement* pstmtGames = con->prepareStatement("SELECT * FROM physicalgames WHERE Games_List_ID = ?");
            pstmtGames->setString(1, gamesListIDInput);
            sql::ResultSet* resGames = pstmtGames->executeQuery();

            if (resGames->next())
            {
                gamesListID = resGames->getInt("Games_List_ID");
            }
            else
            {
                cout << "Games with Games ID " << gamesListIDInput << " not found." << endl;
                delete pstmtGames;
                return;
            }
            delete pstmtGames;
        }

        // Prompt user for Purchase Name
        cout << "Enter Customer Name: ";
        cin.ignore(); // Ignore any previous newline character in the buffer
        getline(cin, purName);

        cout << "Enter Customer Email: ";
        getline(cin, Cus_Email);

        // Prompt user for Purchase Quantity
        cout << "Enter Purchase Quantity: ";
        cin >> purQuantity;

        // Perform the necessary SQL queries and updates here to add the new order to the purchase record
        // Example SQL query (you'll need to adapt this based on your actual database schema):
        string sqlQuery = "INSERT INTO purchasegames(Cus_Email, Games_List_ID, Pur_Name, Pur_Quantity, Pur_Price, Pur_Date) "
            "VALUES (?, ?, ?, ?, (SELECT (Item_Price * ?) FROM physicalgames WHERE Games_List_ID = ?), CURRENT_DATE)";

        sql::PreparedStatement* pstmt = con->prepareStatement(sqlQuery);

        pstmt->setString(1, Cus_Email);


        if (gamesListIDInput != "x")
        {
            pstmt->setInt(2, gamesListID);
        }
        else
        {
            pstmt->setNull(2, sql::DataType::INTEGER);
        }

        pstmt->setString(3, purName);
        pstmt->setInt(4, purQuantity);
        pstmt->setInt(5, purQuantity);  // Pur_Price calculated by multiplying with Pur_Quantity
        if (gamesListIDInput != "x")
        {
            pstmt->setInt(6, gamesListID);  // Games_List_ID for joining with physical_games table
        }
        else
        {
            pstmt->setNull(6, sql::DataType::INTEGER);
        }
        string updateQuantityQuery = "UPDATE physicalgames SET Item_Quantity = Item_Quantity - ? WHERE Games_List_ID = ?";
        sql::PreparedStatement* pstmtUpdateQuantity = con->prepareStatement(updateQuantityQuery);

        pstmtUpdateQuantity->setInt(1, purQuantity);
        pstmtUpdateQuantity->setInt(2, gamesListID);

        pstmtUpdateQuantity->executeUpdate();


        pstmt->executeUpdate();
        delete pstmt;

        // Display the latest purchase details
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM purchasegames ORDER BY Purchase_ID DESC LIMIT 50");

        if (res->next())
        {
            system("cls");  // Clear the console screen
            cout << "\n Purchase Details:\n";
            cout << "+-----------------------------------------------+\n";
            cout << "| Purchase ID       |: " << setw(14) << res->getInt("Purchase_ID") << endl;
            cout << "| Customer Email    |: " << setw(10) << res->getString("Cus_Email") << endl;
            cout << "| Game ID           |: " << setw(18) << res->getInt("Games_List_ID") << endl;
            cout << "| Purchase Name     |: " << setw(13) << res->getString("Pur_Name") << endl;
            cout << "| Purchase Quantity |: " << setw(7) << res->getInt("Pur_Quantity") << endl;
            cout << "| Purchase Price    |: " << setw(10) << res->getDouble("Pur_Price") << endl;
            cout << "| Purchase Date     |: " << setw(15) << res->getString("Pur_Date") << endl;
            cout << "+-----------------------------------------------+\n";

            // Ask if the customer wants a receipt
            char printReceipt;
            cout << "Do you want a receipt? (y/n): ";
            printReceipt = _getch();

            if (printReceipt == 'y' || printReceipt == 'Y')
            {
                // Print the receipt to a new .txt file
                printReceiptToFileGames(res, con);
            }
        }

        delete res;
        delete stmt;

        cout << "Order placed successfully!" << endl;

    }
    /*
    catch (sql::SQLException& e)
    {
        cout << "SQL Error: " << e.what() << endl;
    }
    catch (const std::exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    */
    catch (...)
    {
        cout << "Some data entered are wrong. Please re-enter." << endl;
    }
}


void orderNewDevice(sql::Connection* con)
{
    try
    {
        con->setSchema("database");  // Replace 'your_database_name' with your actual database name

        // Prompt the user for order details
        string devicesListIDInput;
        int purQuantity;
        string purName, Cus_Email;

        /*
        // Prompt user for Games_List_ID
        cout << "Enter Games_List_ID : ";
        cin >> gamesListIDInput;

        // Search for Games_List_ID in the physicalgames database
        int gamesListID;
        if (gamesListIDInput != "x") {
            sql::PreparedStatement* pstmtGames = con->prepareStatement("SELECT * FROM physicalgames WHERE Games_List_ID = ?");
            pstmtGames->setString(1, gamesListIDInput);
            sql::ResultSet* resGames = pstmtGames->executeQuery();

            if (resGames->next()) {
                gamesListID = resGames->getInt("Games_List_ID");
            }
            else {
                cout << "Physical Game with Games_List_ID " << gamesListIDInput << " not found." << endl;
                delete pstmtGames;
                return;
            }
            delete pstmtGames;
        }
        */

        // Prompt user for Devices_List_ID
        cout << "Enter Device ID : ";
        cin >> devicesListIDInput;

        // Search for Devices_List_ID in the devices database
        int devicesListID;
        if (devicesListIDInput != "x")
        {
            sql::PreparedStatement* pstmtDevices = con->prepareStatement("SELECT * FROM devices WHERE Devices_List_ID = ?");
            pstmtDevices->setString(1, devicesListIDInput);
            sql::ResultSet* resDevices = pstmtDevices->executeQuery();

            if (resDevices->next())
            {
                devicesListID = resDevices->getInt("Devices_List_ID");
            }
            else
            {
                cout << "Device with Devices_List_ID " << devicesListIDInput << " not found." << endl;
                delete pstmtDevices;
                return;
            }
            delete pstmtDevices;
        }

        // Prompt user for Purchase Name
        cout << "Enter Customer Name: ";
        cin.ignore(); // Ignore any previous newline character in the buffer
        getline(cin, purName);

        cout << "Enter Customer Email: ";
        getline(cin, Cus_Email);

        // Prompt user for Purchase Quantity
        cout << "Enter Purchase Quantity: ";
        cin >> purQuantity;

        // Perform the necessary SQL queries and updates here to add the new order to the purchase record
        // Example SQL query (you'll need to adapt this based on your actual database schema):
        string sqlQuery = "INSERT INTO purchasedevices(Cus_Email, Devices_List_ID, Pur_Name, Pur_Quantity, Pur_Price, Pur_Date) "
            "VALUES (?, ?, ?, ?, (SELECT (Item_Price * ?) FROM devices WHERE Devices_List_ID = ?), CURRENT_DATE)";

        sql::PreparedStatement* pstmt = con->prepareStatement(sqlQuery);

        pstmt->setString(1, Cus_Email);


        if (devicesListIDInput != "x")
        {
            pstmt->setInt(2, devicesListID);
        }
        else
        {
            pstmt->setNull(2, sql::DataType::INTEGER);
        }

        pstmt->setString(3, purName);
        pstmt->setInt(4, purQuantity);
        pstmt->setInt(5, purQuantity);  // Pur_Price calculated by multiplying with Pur_Quantity
        if (devicesListIDInput != "x")
        {
            pstmt->setInt(6, devicesListID);  // Games_List_ID for joining with physical_games table
        }
        else
        {
            pstmt->setNull(6, sql::DataType::INTEGER);
        }

        string updateQuantityQuery = "UPDATE devices SET Item_Quantity = Item_Quantity - ? WHERE Devices_List_ID = ?";
        sql::PreparedStatement* pstmtUpdateQuantity = con->prepareStatement(updateQuantityQuery);

        pstmtUpdateQuantity->setInt(1, purQuantity);
        pstmtUpdateQuantity->setInt(2, devicesListID);

        pstmtUpdateQuantity->executeUpdate();

        pstmt->executeUpdate();
        delete pstmt;

        // Display the latest purchase details
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM purchasedevices ORDER BY Purchase_ID DESC LIMIT 50");

        if (res->next())
        {
            system("cls");  // Clear the console screen
            cout << "\n Purchase Details:\n";
            cout << "+-----------------------------------------------+\n";
            cout << "| Purchase ID       |: " << setw(14) << res->getInt("Purchase_ID") << endl;
            cout << "| Customer Email    |: " << setw(10) << res->getString("Cus_Email") << endl;
            cout << "| Device ID         |: " << setw(18) << res->getInt("Devices_List_ID") << endl;
            cout << "| Purchase Name     |: " << setw(13) << res->getString("Pur_Name") << endl;
            cout << "| Purchase Quantity |: " << setw(7) << res->getInt("Pur_Quantity") << endl;
            cout << "| Purchase Price    |: " << setw(10) << res->getDouble("Pur_Price") << endl;
            cout << "| Purchase Date     |: " << setw(15) << res->getString("Pur_Date") << endl;
            cout << "+-----------------------------------------------+\n";


            // Ask if the customer wants a receipt
            char printReceipt;
            cout << "Do you want a receipt? (y/n): ";
            printReceipt = _getch();

            if (printReceipt == 'y' || printReceipt == 'Y')
            {
                // Print the receipt to a new .txt file
                printReceiptToFileDevices(res,con);
            }
        }

      

        delete res;
        delete stmt;

        cout << "Order placed successfully!" << endl;
    }
    /*
    catch (sql::SQLException& e)
    {
        cout << "SQL Error: " << e.what() << endl;
    }
    catch (const std::exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    */
    catch (...)
    {
        cout << "Some data entered are wrong. Please re-enter." << endl;
    }
}

    
void printReceiptToFileGames(sql::ResultSet* res, sql::Connection* con)
{
    // Create a new .txt file for the receipt
    string fileName = "Receipt Purchase Game ID" + to_string(res->getInt("Purchase_ID")) + ".txt";
    ofstream receiptFile(fileName);
    system("cls");  // Clear the console screen

    receiptFile << "\n Purchase Receipt:\n";
    receiptFile << "+-----------------------------------------------+\n";
    receiptFile << "| Purchase ID       |: " << res->getInt("Purchase_ID") << endl;
    receiptFile << "| Customer Email    |: " << res->getString("Cus_Email") << endl;
    receiptFile << "| Game ID           |: " << res->getInt("Games_List_ID") << endl;
    receiptFile << "| Purchase Name     |: " << res->getString("Pur_Name") << endl;
    receiptFile << "| Purchase Quantity |: " << res->getInt("Pur_Quantity") << endl;
    receiptFile << "| Purchase Price    |: " << res->getDouble("Pur_Price") << endl;
    receiptFile << "| Purchase Date     |: " << res->getString("Pur_Date") << endl;
    receiptFile << "+-----------------------------------------------+\n";


    // Get the latest Purchase_ID
    int latestPurchaseID = res->getInt("Purchase_ID");

    // Get the Devices_List_ID from the latest purchase
    int latestDevicesListID = res->getInt("Games_List_ID");

    // Retrieve the Item_Name from devices table using the latest Devices_List_ID
    string item_name_query = "SELECT Item_Name FROM physicalgames WHERE Games_List_ID = ?";
    sql::PreparedStatement* pstmtItemName = con->prepareStatement(item_name_query);
    pstmtItemName->setInt(1, latestDevicesListID);
    sql::ResultSet* resItemName = pstmtItemName->executeQuery();

    string itemName;
    if (resItemName->next()) {
        itemName = resItemName->getString("Item_Name");
    }
    delete pstmtItemName;
    delete resItemName;

    // Insert a new entry into the warrantydevices table
    string insertWarrantyQuery = "INSERT INTO warrantygames(Purchase_ID, Wty_name, Wty_Condition, Wty_Date) "
        "VALUES (?, ?, 'VERIFIED', CURRENT_DATE + INTERVAL 1 YEAR)";

    sql::PreparedStatement* pstmtInsertWarranty = con->prepareStatement(insertWarrantyQuery);

    pstmtInsertWarranty->setInt(1, latestPurchaseID);
    pstmtInsertWarranty->setString(2, itemName);

    pstmtInsertWarranty->executeUpdate();

    delete pstmtInsertWarranty;


    // Fetch warranty details from the warrantydevices table
    sql::PreparedStatement* pstmtWarranty = con->prepareStatement("SELECT * FROM warrantygames WHERE Purchase_ID = ?");
    pstmtWarranty->setInt(1, res->getInt("Purchase_ID"));
    sql::ResultSet* resWarranty = pstmtWarranty->executeQuery();

    // Check if warranty information is available
    if (resWarranty->next())
    {
        receiptFile << "\n Warranty Details \n" << endl;
        receiptFile << "+-----------------------------------------------+\n";
        receiptFile << "Warranty ID           |: " << resWarranty->getInt("Warranty_ID") << endl;
        receiptFile << "Purchase ID           |: " << resWarranty->getInt("Purchase_ID") << endl;
        receiptFile << "Item Name             |: " << resWarranty->getString("Wty_name") << endl;
        receiptFile << "Warranty Condition    |: " << resWarranty->getString("Wty_Condition") << endl;
        receiptFile << "Warranty Lasts Until  |: " << resWarranty->getString("Wty_Date") << endl;
        receiptFile << "+-----------------------------------------------+\n";
    }


    receiptFile.close();

    cout << "Receipt printed successfully! Check the file '" << fileName << "'." << endl;

    delete pstmtWarranty;
    delete resWarranty;
}

void printReceiptToFileDevices(sql::ResultSet* res, sql::Connection* con)
{
    // Create a new .txt file for the receipt
    string fileName = "Receipt Purchase Device ID" + to_string(res->getInt("Purchase_ID")) + ".txt";
    ofstream receiptFile(fileName);

    system("cls");  // Clear the console screen
    receiptFile << "\n Purchase Receipt:\n";
    receiptFile << "+-----------------------------------------------+\n";
    receiptFile << "| Purchase ID       |: " << res->getInt("Purchase_ID") << endl;
    receiptFile << "| Customer Email    |: " << res->getString("Cus_Email") << endl;
    receiptFile << "| DeviceID          |: " << res->getInt("Devices_List_ID") << endl;
    receiptFile << "| Purchase Name     |: " << res->getString("Pur_Name") << endl;
    receiptFile << "| Purchase Quantity |: " << res->getInt("Pur_Quantity") << endl;
    receiptFile << "| Purchase Price    |: " << res->getDouble("Pur_Price") << endl;
    receiptFile << "| Purchase Date     |: " << res->getString("Pur_Date") << endl;
    receiptFile << "+-----------------------------------------------+\n";

    // Get the latest Purchase_ID
    int latestPurchaseID = res->getInt("Purchase_ID");

    // Get the Devices_List_ID from the latest purchase
    int latestDevicesListID = res->getInt("Devices_List_ID");

    // Retrieve the Item_Name from devices table using the latest Devices_List_ID
    string item_name_query = "SELECT Item_Name FROM devices WHERE Devices_List_ID = ?";
    sql::PreparedStatement* pstmtItemName = con->prepareStatement(item_name_query);
    pstmtItemName->setInt(1, latestDevicesListID);
    sql::ResultSet* resItemName = pstmtItemName->executeQuery();

    string itemName;
    if (resItemName->next()) {
        itemName = resItemName->getString("Item_Name");
    }
    delete pstmtItemName;
    delete resItemName;

    // Insert a new entry into the warrantydevices table
    string insertWarrantyQuery = "INSERT INTO warrantydevices(Purchase_ID, Wty_name, Wty_Condition, Wty_Date) "
        "VALUES (?, ?, 'VERIFIED', CURRENT_DATE + INTERVAL 1 YEAR)";

    sql::PreparedStatement* pstmtInsertWarranty = con->prepareStatement(insertWarrantyQuery);

    pstmtInsertWarranty->setInt(1, latestPurchaseID);
    pstmtInsertWarranty->setString(2, itemName);

    pstmtInsertWarranty->executeUpdate();

    delete pstmtInsertWarranty;

    
    // Fetch warranty details from the warrantydevices table
    sql::PreparedStatement * pstmtWarranty = con->prepareStatement("SELECT * FROM warrantydevices WHERE Purchase_ID = ?");
    pstmtWarranty->setInt(1, res->getInt("Purchase_ID"));
    sql::ResultSet* resWarranty = pstmtWarranty->executeQuery();

    // Check if warranty information is available
    if (resWarranty->next())
    {
        receiptFile << "\n Warranty Details \n" << endl;
        receiptFile << "+-----------------------------------------------+\n";
        receiptFile << "Warranty ID           |: " << resWarranty->getInt("Warranty_ID") << endl;
        receiptFile << "Purchase ID           |: " << resWarranty->getInt("Purchase_ID") << endl;
        receiptFile << "Item Name             |: " << resWarranty->getString("Wty_name") << endl;
        receiptFile << "Warranty Condition    |: " << resWarranty->getString("Wty_Condition") << endl;
        receiptFile << "Warranty Lasts Until  |: " << resWarranty->getString("Wty_Date") << endl;
        receiptFile << "+-----------------------------------------------+\n";
    }

    receiptFile.close();

    cout << "Receipt printed successfully! Check the file '" << fileName << "'." << endl;

    delete pstmtWarranty;
    delete resWarranty;
}




/*
void showOrder(sql::Connection* con, const string& customerEmail)
{
    // Implement logic to connect to the database and show the customer's existing orders
    // Retrieve and display relevant information from the purchase record.

    // Example (you'll need to modify and expand this based on your actual database schema):
    try
    {
        con->setSchema("database");  // Replace 'your_database_name' with your actual database name

        // Perform the necessary SQL queries and retrieve purchase records for the customer
        // Example SQL query (you'll need to adapt this based on your actual database schema):
        string sqlQuery = "SELECT * FROM purchase_record WHERE Cus_Email = ?";

        sql::PreparedStatement* pstmt = con->prepareStatement(sqlQuery);
        pstmt->setString(1, customerEmail);

        sql::ResultSet* res = pstmt->executeQuery();

        // Display the retrieved purchase records
        while (res->next())
        {
            cout << "Purchase ID: " << res->getInt("Purchase_ID") << endl;
            // Display other relevant information from the purchase record
        }

        delete res;
        delete pstmt;
    }
    catch (sql::SQLException e)
    {
        cout << "Error showing orders. Error message: " << e.what() << endl;
    }
}
*/