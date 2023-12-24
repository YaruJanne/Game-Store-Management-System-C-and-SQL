#include "Header.h"


bool staffLogin()
{
    string enteredEmail, enteredPassword;

    cout << "Enter Email: ";
    cin >> enteredEmail;

    cout << "Enter Password: ";
    cin >> enteredPassword;

    // Fixed email and password for demonstration purposes
    const string fixedEmail = "1";
    const string fixedPassword = "2";

    if (enteredEmail == fixedEmail && enteredPassword == fixedPassword)
    {
        cout << "Login successful!" << endl;
        return true;
    }
    else
    {
        cout << "Invalid email or password. Login failed." << endl;
        return false;
    }
}

void staffMenu(sql::Connection* con)
{
    int staffChoice;

    do
    {
        cout << "\nStaff Menu:" << endl;
        cout << "1. Add new Item" << endl;
        cout << "2. Edit Item" << endl;
        cout << "3. Delete Item" << endl;
        cout << "4. Show Item" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> staffChoice;

        switch (staffChoice)
        {
        case 1:
            int itemTypeChoice;
            cout << "\nChoose the item type:" << endl;
            cout << "1. Physical Game" << endl;
            cout << "2. Device" << endl;
            cout << "Enter your choice (1 or 2): ";
            cin >> itemTypeChoice;

            if (itemTypeChoice == 1)
            {
                addNewPhysicalGame(con);
            }
            else if (itemTypeChoice == 2)
            {
                addNewDevice(con);
            }
            else
            {
                cout << "Invalid item type choice." << endl;
            }

            break;
        case 2:
            int EdititemTypeChoice;
            cout << "\nChoose the item type:" << endl;
            cout << "1. Physical Game" << endl;
            cout << "2. Device" << endl;
            cout << "Enter your choice (1 or 2): ";
            cin >> EdititemTypeChoice;

            if (EdititemTypeChoice == 1)
            {
                editPhysicalGame(con);
            }
            else if (EdititemTypeChoice == 2)
            {
                editDevice(con);
            }
            else
            {
                cout << "Invalid item type choice." << endl;
            }
            break;
        case 3:
            int DeleteitemTypeChoice;
            cout << "\nChoose the item type:" << endl;
            cout << "1. Physical Game" << endl;
            cout << "2. Device" << endl;
            cout << "Enter your choice (1 or 2): ";
            cin >> DeleteitemTypeChoice;

            if (DeleteitemTypeChoice == 1)
            {
                deletePhysicalGame(con);
            }
            else if (DeleteitemTypeChoice == 2)
            {
                deleteDevice(con);
            }
            else
            {
                cout << "Invalid item type choice." << endl;
            }
            break;
        case 4:
            int showItemTypeChoice;
            cout << "\nChoose the item type to show:" << endl;
            cout << "1. Physical Games" << endl;
            cout << "2. Devices" << endl;
            cout << "Enter your choice (1 or 2): ";
            cin >> showItemTypeChoice;

            if (showItemTypeChoice == 1)
            {
                showPhysicalGames(con);
            }
            else if (showItemTypeChoice == 2)
            {
                showDevices(con);
            }
            else
            {
                cout << "Invalid item type choice." << endl;
            }
            break;
        case 5:
            int choice;  // Declare the choice variable here

            cout << "\nWelcome to the Inventory Management System!" << endl;
            cout << "1. Customer" << endl;
            cout << "2. Staff" << endl;
            cout << "Enter your choice (1 or 2): ";

            cin >> choice;  // Initialize the choice variable

            switch (choice)
            {
            case 1:
                processCustomer(con, choice);  // Pass the choice variable to processCustomer
                break;
            case 2:
                processStaff(con);
                break;
            default:
                cout << "Invalid choice. Exiting." << endl;
                break;
            }
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            break;
        }

        // Check if the user pressed 'x' to return to the staff menu
        if (staffChoice != 5)
        {
            char returnToMenu;
            cout << "Press 'x' to return to the staff menu: ";
            cin >> returnToMenu;

            if (returnToMenu != 'x')
            {
                cout << "Invalid input. Returning to the staff menu." << endl;
                staffChoice = 0;  // Set staffChoice to an invalid value to loop back
            }
        }
    } while (staffChoice != 5);

    // Additional staff functionality can be implemented here
    // For example, handling orders, managing staff details, etc.
    cout << "Staff functionality coming soon!" << endl;
}

void processStaff(sql::Connection* con)
{
    if (staffLogin())
    {
        staffMenu(con);
    }
    else
    {
        cout << "Login failed. Exiting staff menu." << endl;
    }
}