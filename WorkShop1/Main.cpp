#include "Header.h"

//for demonstration only. never save your password in the code!
const string server = "tcp://127.0.0.1:3306";
const string username = "root";
const string password = "";

void processCustomer(sql::Connection* con);
void processStaff(sql::Connection* con);

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

    cout << "Welcome to the Inventory Management System!" << endl;
    cout << "1. Customer" << endl;
    cout << "2. Staff" << endl;
    cout << "Enter your choice (1 or 2): ";

    int choice;
    cin >> choice;

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



void processStaff(sql::Connection* con)
{
    sql::Statement* stmt;

    try
    {
        con->setSchema("database");

        stmt = con->createStatement();
        stmt->execute("DROP TABLE IF EXISTS inventory");
        cout << "Finished dropping table (if existed)" << endl;
        stmt->execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);");
        cout << "Finished creating table" << endl;
        delete stmt;

        sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO inventory(name, quantity) VALUES(?,?)");
        pstmt->setString(1, "banana");
        pstmt->setInt(2, 150);
        pstmt->execute();
        cout << "One row inserted." << endl;

        pstmt->setString(1, "orange");
        pstmt->setInt(2, 154);
        pstmt->execute();
        cout << "One row inserted." << endl;

        pstmt->setString(1, "apple");
        pstmt->setInt(2, 100);
        pstmt->execute();
        cout << "One row inserted." << endl;

        delete pstmt;

        // Add more staff-specific functionality here
        // For example, managing inventory, processing orders, etc.
        cout << "Staff functionality coming soon!" << endl;
    }
    catch (sql::SQLException e)
    {
        cout << "Error processing staff request. Error message: " << e.what() << endl;
    }
}
