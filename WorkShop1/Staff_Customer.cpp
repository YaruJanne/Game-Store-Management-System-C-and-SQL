//Staff_Customer

#include "Header.h"


void showCustomerInfo(sql::Connection* con)
{
    system("cls");  // Clear the console screen
    try
    {
        // Connect to the database
        con->setSchema("database");  // Replace 'your_database_name' with your actual database name

        // Fetch data from the warrantygames table
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM customer");

        // Display the column names
        cout << "\nCustomer Table:\n";
        cout << "------------------------------------------------------------------------------------\n";

        int columnCount = res->getMetaData()->getColumnCount();

        for (int i = 1; i <= columnCount; ++i) {
            cout << res->getMetaData()->getColumnName(i) << " | ";
        }

        cout << "\n------------------------------------------------------------------------------------\n";

        // Display the data
        while (res->next()) {
            for (int i = 1; i <= columnCount; ++i) {
                cout << left;
                cout << res->getString(i) << " | ";
            }
            cout << endl;
        }

        cout << "-------------------------------------------------------------------------\n";

        // Ask if the user wants to return to the staff main menu
        char returnToMenu;
        cout << "Press 'x' to return to the Staff Main Menu: ";
        cin >> returnToMenu;

        if (returnToMenu != 'x')
        {
            cout << "Invalid input. Returning to the Staff Main Menu." << endl;
        }
        else
        {
            cout << "Going back to Staff Main Menu." << endl;
        }

        // Clean up
        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e)
    {
        cout << "SQL Error: " << e.what() << endl;
    }
    catch (const std::exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "An unexpected error occurred." << endl;
    }
}


