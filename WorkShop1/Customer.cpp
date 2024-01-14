// Customer.cpp

#include "Header.h"




bool loginCustomer(sql::Connection* con, int& customerId)
{
    
    // Get user input for login
    string email, password;
    char confirmation;
    system("cls");  // Clear the console screen

    cout << "Do you want to continue with the login? (y/n): ";
    cin >> confirmation;
  
    if (confirmation == 'y' || confirmation == 'Y')
    {
        std::cout << "+----------------------------------------+" << std::endl;
        std::cout << "|              Customer Login            |" << std::endl;
        std::cout << "|----------------------------------------|" << std::endl;


        std::cout << "| Enter Email    | : ";
        cin.ignore();
        getline(cin, email);


        std::cout << "| Enter Password | : ";
        getline(cin, password);
        std::cout << "+----------------------------------------+" << std::endl;


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
                system("cls");  // Clear the console screen
                cout << " \nLogin Success." << endl;
                enterCustomer(con);
                delete pstmt;

            }
            else  
            {
                system("cls");  // Clear the console screen
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
    else
    {
        cout << "Registration canceled. Returning to the Customer Options." << endl;
        processCustomer(con);
    }
}

void registerCustomer(sql::Connection* con)
{
    system("cls");  // Clear the console screen
    // Get user input for registration
    string name, telno, email, password;
    char confirmation;

    cout << "Do you want to continue with the registration? (y/n): ";
    cin >> confirmation;
  
    
    if (confirmation == 'y' || confirmation == 'Y') {

        std::cout << "+------------------------------------------------+" << std::endl;
        std::cout << "|              Customer Registration             |" << std::endl;
        std::cout << "|------------------------------------------------|" << std::endl;

        std::cout << "| Enter Name | : " << std::endl;
        cin.ignore();
        getline(cin, name);

        std::cout << "| Enter Telephone Number | : " << std::endl;
        getline(cin, telno);

        std::cout << "| Enter Email | : " << std::endl;
        getline(cin, email);

        std::cout << "| Enter Password | : " << std::endl;
        getline(cin, password);
        std::cout << "|------------------------------------------------|" << std::endl;

        try {
            con->setSchema("database");  // Replace 'your_database_name' with your actual database name

            sql::PreparedStatement* pstmt = con->prepareStatement(
                "INSERT INTO customer (Cus_Name, Cus_Telno, Cus_Email, Cus_password) VALUES (?, ?, ?, ?)");

            pstmt->setString(1, name);
            pstmt->setString(2, telno);
            pstmt->setString(3, email);
            pstmt->setString(4, password);

            pstmt->execute();
            delete pstmt;

            cout << "Registration successful! Thank you for registering." << endl;
        }
        catch (sql::SQLException e) {
            cout << "Error registering customer. Error message: " << e.what() << endl;
        }
    }
    else
    {
        cout << "Registration canceled. Returning to the Customer Options." << endl;
        processCustomer(con);
    }
    
}



void processCustomer(sql::Connection* con)
{
    system("cls");  // Clear the console screen
    int customerOption;
    int customerID = 0;  // Variable to store the logged-in customer's ID
    bool exitToMainMenu = false;
    do
    {
        std::cout << "+-----------------------------+" << std::endl;
        std::cout << "|       Customer Options      |" << std::endl;
        std::cout << "|-----------------------------|" << std::endl;
        std::cout << "| 1. Login                    |" << std::endl;
        std::cout << "| 2. Register                 |" << std::endl;
        std::cout << "| 3. Exit to Main Menu        |" << std::endl;
        std::cout << "|-----------------------------|" << std::endl;
        std::cout << "|      Enter your choice      |" << std::endl;
        std::cout << "|        (1, 2, or 3)         |" << std::endl;
        std::cout << "+-----------------------------+" << std::endl;
        cin >> customerOption;

        switch (customerOption)
        {
        case 1:
            system("cls");  // Clear the console screen

            if (loginCustomer(con, customerID))
            {
                system("cls");  // Clear the console screen
                // Login successful, continue to customer menu
                cout << "Login successful! Welcome, Customer " << customerID << "!" << endl;
                // Call other functions or perform actions for the logged-in customer
            }
            break;
        case 2:
            system("cls");  // Clear the console screen

            registerCustomer(con);
            break;
        case 3:
            // Set the flag to true to indicate the desire to exit to Main Menu
            exitToMainMenu = true;
            return;  // Use return to exit the function and go back to int main
            break;
        default:
            system("cls");  // Clear the console screen

            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
            break;
        }

    } while (customerOption != 3);
}

void enterCustomer(sql::Connection* con)
{
    char customerChoice;  // Declare the variable outside the loop
    system("cls");  // Clear the console screen
    do
    {
        std::cout << "+---------------------------+" << std::endl;
        std::cout << "|        Customer Menu      |" << std::endl;
        std::cout << "|---------------------------|" << std::endl;
        std::cout << "| 1. Physical Game          |" << std::endl;
        std::cout << "| 2. Device                 |" << std::endl;
        std::cout << "| 3. Exit to Main Menu      |" << std::endl;
        std::cout << "+---------------------------+" << std::endl;
        customerChoice = _getch() - '0';

        switch (customerChoice)
        {
        case 1:
            system("cls");  // Clear the console screen
            showPhysicalGames(con);
            break;
        case 2:
            system("cls");  // Clear the console screen
            showDevices(con);
            break;
        case 3:
            system("cls");  // Clear the console screen
            cout << "\nExiting to Main Menu." << endl;
            processCustomer(con);
            break;
        default:

            cout << "\nInvalid choice. Please enter 1, 2, or 3." << endl;
            break;
        }

       
    } while (customerChoice != 3);  // Repeat the loop until the user chooses to exit
}