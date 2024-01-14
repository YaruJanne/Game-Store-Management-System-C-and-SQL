//Admin Warranty.cpp

#include "Header.h"

void purchaseRecordMenu(sql::Connection* con)
{
    char purchaseRecordChoice;

    do
    {
        system("cls");  // Clear the console screen
        cout << "+---------------------------+\n";
        cout << "|    Purchase Record Menu   |\n";
        cout << "+---------------------------+\n";
        cout << "| 1. Physical Games         |\n";
        cout << "| 2. Devices                |\n";
        cout << "| 3. Back to Admin Main Menu|\n";
        cout << "+---------------------------+\n";
        cout << "|  Enter your choice (1-3)  |\n";
        cout << "+---------------------------+\n";
        purchaseRecordChoice = _getch() - '0';

        switch (purchaseRecordChoice)
        {
        case 1:
            system("cls");  // Clear the console screen
            showPurchaseGames(con);
            break;
        case 2:
            system("cls");  // Clear the console screen
            showPurchaseDevices(con);
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

    } while (purchaseRecordChoice != 3);
}

void showPurchaseGames(sql::Connection* con)
{
    system("cls");  // Clear the console screen
    try
    {
        // Connect to the database
        con->setSchema("database");  // Replace 'your_database_name' with your actual database name

        // Fetch data from the purchasegames table
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM purchasegames");

        // Display the data
        cout << "\nPurchase Games Table:\n";
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";
        cout << " Purchase_ID |       Cus_Email      | Games_List_ID |         Pur_Name         | Pur_Quantity | Pur_Price |   Pur_Date  |\n";
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";

        while (res->next())
        {
            cout << "\n" << left;
            cout << setw(14) << res->getInt("Purchase_ID");
            cout << setw(25) << res->getString("Cus_Email");
            cout << setw(15) << res->getInt("Games_List_ID");
            cout << setw(26) << res->getString("Pur_Name");
            cout << setw(15) << res->getInt("Pur_Quantity");
            cout << setw(14) << res->getDouble("Pur_Price");
            cout << setw(14) << res->getString("Pur_Date") << endl;
        }

        cout << "--------------------------------------------------------------------------------------------------------------------\n";

        // Clean up
        delete res;
        delete stmt;

        // Wait for 'x' to return to the purchase record menu
        char returnToMenu;
        cout << "Press 'x' to return to Purchase Record Menu: ";
        cin >> returnToMenu;

        if (returnToMenu != 'x')
        {
            cout << "Invalid input. Returning to the Purchase Record Menu." << endl;
        }
        else
        {
            cout << "Returning to the Purchase Record Menu." << endl;
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

void showPurchaseDevices(sql::Connection* con)
{
    system("cls");  // Clear the console screen
    try
    {
        // Connect to the database
        con->setSchema("database");  // Replace 'your_database_name' with your actual database name

        // Fetch data from the purchasedevices table
        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM purchasedevices");

        // Display the data
        cout << "\nPurchase Devices Table:\n";
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";
        cout << " Purchase_ID |       Cus_Email      | Devices_List_ID |        Pur_Name        | Pur_Quantity | Pur_Price |   Pur_Date  |\n";
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";

        while (res->next())
        {
            cout << "\n" << left;
            cout << setw(14) << res->getInt("Purchase_ID");
            cout << setw(25) << res->getString("Cus_Email");
            cout << setw(15) << res->getInt("Devices_List_ID");
            cout << setw(26) << res->getString("Pur_Name");
            cout << setw(15) << res->getInt("Pur_Quantity");
            cout << setw(14) << res->getDouble("Pur_Price");
            cout << setw(14) << res->getString("Pur_Date") << endl;
        }

        cout << "--------------------------------------------------------------------------------------------------------------------\n";

        // Clean up
        delete res;
        delete stmt;

        // Wait for 'x' to return to the purchase record menu
        char returnToMenu;
        cout << "Press 'x' to return to Purchase Record Menu: ";
        cin >> returnToMenu;

        if (returnToMenu != 'x')
        {
            cout << "Invalid input. Returning to the Purchase Record Menu." << endl;
        }
        else
        {
            cout << "Returning to the Purchase Record Menu." << endl;
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