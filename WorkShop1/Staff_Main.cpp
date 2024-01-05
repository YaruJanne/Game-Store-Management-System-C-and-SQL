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



void staffMain(sql::Connection* con)
{
    int staffChoice;

    do
    {
        cout << "\nStaff Main Menu:" << endl;
        cout << "1. Item List" << endl;
        cout << "2. Staff" << endl;
        cout << "3. Purchase Record" << endl;
        cout << "4. Warranty" << endl;
        cout << "5. Customer" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> staffChoice;

        switch (staffChoice)
        {
        case 1:
            itemMenu(con);  // Go to the itemMenu
            break;
        case 2:
            // Existing code for staff functionality
            break;
        case 3:
            // Existing code for purchase record functionality
            break;
        case 4:
            // Existing code for warranty functionality
            break;
        case 5:
            // Existing code for customer functionality
            break;
        case 6:
            int choice;  // Declare the choice variable here

            cout << "\nWelcome to the Game Store!" << endl;
            cout << "1. Customer" << endl;
            cout << "2. Staff" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice (1, 2, or 3): ";

            cin >> choice;  // Initialize the choice variable

            switch (choice)
            {
            case 1:
                return;
                break;
            case 2:
                processStaff(con);
                break;
            case 3:
                cout << "Exiting Main Menu. Returning to Main Menu." << endl;
                return;  // Exit the staffMenu function, returning to the main menu
            default:
                cout << "Invalid choice. Exiting." << endl;
                break;
            }
            break;  // Exit the staffMenu function, returning to the main menu
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
            break;
        }

        // Check if the user pressed 'x' to return to the main menu
        if (staffChoice != 6)
        {
            char returnToMenu;
            cout << "Press 'x' to return to the Main Menu, or any other key to return to the Main Menu: ";
            cin >> returnToMenu;

            if (returnToMenu != 'x')
            {
                cout << "Returning to the Main Menu." << endl;
                break;  // Exit the loop and return to the main menu
            }
        }
    } while (true);

    // Additional item functionality can be implemented here
    // For example, handling item details, managing item stock, etc.
    cout << "Item functionality coming soon!" << endl;
}


void itemMenu(sql::Connection* con)
{
    int itemChoice;

    do
    {
        cout << "\nItem Menu:" << endl;
        cout << "1. Add new Item" << endl;
        cout << "2. Edit Item" << endl;
        cout << "3. Delete Item" << endl;
        cout << "4. Show Item" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> itemChoice;

        switch (itemChoice)
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
            cout << "Exiting Item Menu. Returning to Staff Menu." << endl;
            return;  // Exit the itemMenu function, returning to the staffMenu
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            break;
        }

        // Check if the user pressed 'x' to return to the staff menu
        if (itemChoice != 5)
        {
            char returnToMenu;
            cout << "Press 'x' to return to the Item Menu: ";
            cin >> returnToMenu;

            if (returnToMenu != 'x')
            {
                cout << "Invalid input. Returning to the Item Menu." << endl;
                itemChoice = 0;  // Set itemChoice to an invalid value to loop back
            }
        }
    } while (itemChoice != 5);

    // Additional item functionality can be implemented here
    // For example, handling item details, managing item stock, etc.
    cout << "Item functionality coming soon!" << endl;
}

void processStaff(sql::Connection* con)
{
    if (staffLogin())
    {
        staffMain(con);
    }
    else
    {
        cout << "Login failed. Exiting staff menu." << endl;
    }
}