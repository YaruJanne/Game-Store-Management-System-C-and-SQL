//Admin_Warranty.cpp

#include "Header.h"

void adminWarranty(sql::Connection* con)
{
    char adminWarranty;
    system("cls");  // Clear the console screen
    do
    {
        cout << "+---------------------------+" << endl;
        cout << "|      Warranty Admin       |" << endl;
        cout << "+---------------------------+" << endl;
        cout << "| 1. Physical Games         |" << endl;
        cout << "| 2. Devices                |" << endl;
        cout << "| 3. Back to Staff Main Menu|" << endl;
        cout << "+---------------------------+" << endl;
        cout << "|  Enter your choice (1-3)  |" << endl;
        cout << "+---------------------------+" << endl;
        adminWarranty = _getch() - '0';

        switch (adminWarranty)
        {
        case 1:
            system("cls");  // Clear the console screen
            showWarrantyGames(con);
            break;
        case 2:
            system("cls");  // Clear the console screen
            showWarrantyDevices(con);
            break;
        case 3:
            // Returning to the staff main menu
            cout << "Returning to Staff Main Menu." << endl;
            return;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
            break;
        }

    } while (adminWarranty != 3);
}


void showWarrantyGames(sql::Connection* con)
{

    system("cls");  // Clear the console screen
    try
    {
        // Connect to the database
        con->setSchema("database");  // Replace 'your_database_name' with your actual database name

        // Fetch data from the warrantygames table
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM warrantygames");

        // Display the data
        cout << "\nWarranty Games Table:\n";
        cout << "-------------------------------------------------------------------------------------\n";
        cout << "Warranty_ID | Purchase_ID |        Wty_Name        |   Wty_Condition   |   Wty_Date  \n";
        cout << "-------------------------------------------------------------------------------------\n";

        while (res->next())
        {
            cout << "\n" << left;
            cout << setw(12) << res->getInt("Warranty_ID");
            cout << setw(14) << res->getInt("Purchase_ID");
            cout << setw(27) << res->getString("Wty_name");
            cout << setw(20) << res->getString("Wty_Condition");
            cout << setw(12) << res->getString("Wty_Date") << endl;
        }

        cout << "------------------------------------------------------------------------------------\n";

        // Clean up
        delete res;
        delete stmt;

        // Wait for 'x' to return to the warranty record menu
        char returnToMenu;
        cout << "Press 'x' to return to Warranty Menu: ";
        cin >> returnToMenu;

        if (returnToMenu != 'x')
        {
            cout << "Invalid input. Returning to the Warranty Menu." << endl;
        }
        else
        {
            cout << "Returning to the Warranty Menu." << endl;
        }
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

void showWarrantyDevices(sql::Connection* con)
{
    system("cls");  // Clear the console screen
    try
    {
        system("cls");  // Clear the console screen
        // Connect to the database
        con->setSchema("database");  // Replace 'your_database_name' with your actual database name

        // Fetch data from the warrantydevices table
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM warrantydevices");

        // Display the data
        cout << "\nWarranty Devices Table:\n";
        cout << "-------------------------------------------------------------------------------------\n";
        cout << "Warranty_ID | Purchase_ID |        Wty_Name        |   Wty_Condition   |   Wty_Date  \n";
        cout << "-------------------------------------------------------------------------------------\n";

        while (res->next())
        {
            cout << "\n" << left;
            cout << setw(12) << res->getInt("Warranty_ID");
            cout << setw(14) << res->getInt("Purchase_ID");
            cout << setw(27) << res->getString("Wty_name");
            cout << setw(20) << res->getString("Wty_Condition");
            cout << setw(12) << res->getString("Wty_Date") << endl;
        }

        cout << "------------------------------------------------------------------------------------\n";

        // Clean up
        delete res;
        delete stmt;

        // Wait for 'x' to return to the warranty record menu
        char returnToMenu;
        cout << "Press 'x' to return to Warranty Menu: ";
        cin >> returnToMenu;

        if (returnToMenu != 'x')
        {
            cout << "Invalid input. Returning to the Warranty Menu." << endl;
        }
        else
        {
            cout << "Returning to the Warranty Menu." << endl;
        }
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
