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

    int choice;  // Declare the choice variable here

    cout << "\nWelcome to the Game Store!" << endl;
    cout << "1. Customer" << endl;
    cout << "2. Staff" << endl;
    cout << "Enter your choice (1 or 2): ";

    cin >> choice;  // Initialize the choice variable

    switch (choice)
    {
    case 1:
        processCustomer(con);
        break;
    case 2:
        processStaff(con);
        break;
    default:
        cout << "Invalid choice. Exiting." << endl;
        break;
    }

    delete con;
    system("pause");
    return 0;
}
