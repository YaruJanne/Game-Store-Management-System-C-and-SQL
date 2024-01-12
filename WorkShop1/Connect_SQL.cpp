// main.cpp

#include "Header.h"

const string server = "tcp://127.0.0.1:3306";
const string username = "root";
const string password = "";

int main()
{
    sql::Driver* driver;
    sql::Connection* con;

    try
    {
        driver = get_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException e)
    {
        cout << "Could not connect to the server. Error message: " << e.what() << endl;
        system("pause");
        exit(1);
    }

    char choice;

    do
    {
        cout << "\nWelcome to the Game Store!" << endl;
        cout << "1. Customer" << endl;
        cout << "2. Staff" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1, 2, or 3): ";

        choice = _getch() - '0';

        switch (choice)
        {
        case 1:
            processCustomer(con);
            break;
        case 2:
            processStaff(con);
            break;
        case 3:
            cout << "Exiting Main Menu. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
            break;
        }

    } while (choice != 3);

    delete con;
    system("pause");
    return 0;
}