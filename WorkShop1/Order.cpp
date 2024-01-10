//Order.cpp

#include "Header.h"



void orderMenu(sql::Connection* con);

void orderMenu(sql::Connection* con)
{
    int orderChoice;

    do
    {
        cout << "\nOrder Menu:" << endl;
        cout << "1. Order" << endl;
        cout << "2. Show Order" << endl;
        cout << "3. Exit to Customer Menu" << endl;
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> orderChoice;

        switch (orderChoice)
        {
        case 1:
            // Order new items
            // Implement logic to interact with the purchase record in the database
            // You can create a function for this, e.g., orderNewItems(con, customerEmail);
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

void orderNewItems(sql::Connection* con, const string& customerEmail)
{
    try
    {
        con->setSchema("database");  // Replace 'your_database_name' with your actual database name

        // Prompt the user for order details
        int gamesListID, devicesListID, purQuantity;
        string purName;

        cout << "Enter Games_List_ID: ";
        cin >> gamesListID;

        cout << "Enter Devices_List_ID: ";
        cin >> devicesListID;

        cout << "Enter Pur_Name: ";
        cin.ignore();
        getline(cin, purName);

        cout << "Enter Pur_Quantity: ";
        cin >> purQuantity;

        // Perform the necessary SQL queries and updates here to add the new order to the purchase record
        // Calculate Pur_Price by joining item prices from the physical games and devices tables
        // and multiplying with Pur_Quantity.

        // Example SQL query (you'll need to adapt this based on your actual database schema):
        string sqlQuery = "INSERT INTO purchase_record (Cus_Email, Games_List_ID, Devices_List_ID, Pur_Name, Pur_Quantity, Pur_Price, Pur_Date) "
            "VALUES (?, ?, ?, ?, ?, (SELECT (Price * ?) FROM physical_games WHERE Games_List_ID = ?), CURRENT_DATE)";

        sql::PreparedStatement* pstmt = con->prepareStatement(sqlQuery);
        pstmt->setString(1, customerEmail);
        pstmt->setInt(2, gamesListID);
        pstmt->setInt(3, devicesListID);
        pstmt->setString(4, purName);
        pstmt->setInt(5, purQuantity);
        pstmt->setInt(6, purQuantity);  // Pur_Price calculated by multiplying with Pur_Quantity
        pstmt->setInt(7, gamesListID);  // Games_List_ID for joining with physical_games table

        pstmt->executeUpdate();
        delete pstmt;

        cout << "Order placed successfully!" << endl;
    }
    catch (sql::SQLException e)
    {
        cout << "Error placing order. Error message: " << e.what() << endl;
    }
}

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