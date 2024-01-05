// Customer.cpp

#include "Header.h"

bool loginCustomer(sql::Connection* con, int& customerId)
{
    cout << "\nCustomer Login:" << endl;

    // Get user input for login
    string email, password;

    cout << "Enter Email: ";
    cin.ignore();
    getline(cin, email);

    cout << "Enter Password: ";
    getline(cin, password);

    try
    {
        con->setSchema("database");  // Replace 'your_database_name' with your actual database name

        // Check if the entered email and password match a customer in the database
        sql::PreparedStatement* pstmt = con->prepareStatement(
            "SELECT Cus_Name FROM customer WHERE Cus_Email = ? AND Cus_password = ?");
        pstmt->setString(1, email);
        pstmt->setString(2, password);

        sql::ResultSet* res = pstmt->executeQuery();

        if (res->next())
        {
            cout << " Login Success." << endl;
            processCustomer(con);
            delete pstmt;
           
        }
        else
        {
            cout << "Wrong email or password. Login failed." << endl;
            delete res;
            delete pstmt;
            return false;  // Login failed
        }
    }
    catch (sql::SQLException e)
    {
        cout << "Error logging in. Error message: " << e.what() << endl;
        return false;  // Return false on error
    }
}

void registerCustomer(sql::Connection* con)
{
    cout << "\nCustomer Registration:" << endl;

    // Get user input for registration
    string name, telno, email, password;

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter Telephone Number: ";
    getline(cin, telno);

    cout << "Enter Email: ";
    getline(cin, email);

    cout << "Enter Password: ";
    getline(cin, password);

    try
    {
        con->setSchema("database");  // Replace 'your_database_name' with your actual database name

        // Automatically assign Customer_ID starting with 01 for every registration
        //int newCustomerId = getNextCustomerId(con);

        // Insert the new customer into the database
        sql::PreparedStatement* pstmt = con->prepareStatement(
            "INSERT INTO customer (Cus_Name, Cus_Telno, Cus_Email, Cus_password) VALUES ( ?, ?, ?, ?)");

  
        pstmt->setString(1, name);
        pstmt->setString(2, telno);
        pstmt->setString(3, email);
        pstmt->setString(4, password);

        pstmt->execute();
        delete pstmt;

        //cout << "Registration successful! Your Customer_ID is: " <<  << endl;
    }
    catch (sql::SQLException e)
    {
        cout << "Error registering customer. Error message: " << e.what() << endl;
    }
}

// Customer.cpp

void processCustomer(sql::Connection* con)
{
    int customerOption;
    int customerID = 0;  // Variable to store the logged-in customer's ID

    do
    {
        cout << "\nCustomer Options:" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit to Main Menu" << endl;
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> customerOption;

        switch (customerOption)
        {
        case 1:
            if (loginCustomer(con, customerID))
            {
                // Login successful, continue to customer menu
                cout << "Login successful! Welcome, Customer " << customerID << "!" << endl;
                // Call other functions or perform actions for the logged-in customer
            }
            break;
        case 2:
            registerCustomer(con);
            break;
        case 3:
            // Returning to the main menu
            cout << "Returning to the Main Menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
            break;
        }

    } while (customerOption != 3);
}

