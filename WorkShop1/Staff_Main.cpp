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
    char staffChoice;

    do
    {
        cout << "\nStaff Main Menu:" << endl;
        cout << "1. Item List" << endl;
        cout << "2. Purchase Record" << endl;
        cout << "3. Warranty" << endl;
        cout << "4. Customer" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        //cin >> 
        staffChoice = _getch() - '0';

        switch (staffChoice)
        {
        case 1:
            itemMenu(con);  // Go to the itemMenu
            break;
        case 2:
            purchaseRecordMenu(con);
            break;
        case 3:
            adminWarranty(con);
            break;
        case 4:
            // Existing code for customer functionality
            break;
        case 5:
            // Returning to the main menu
            cout << "Returning to the Main Menu." << endl;
            return;  // Use return to exit the function and go back to int main
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            break;
        }

    } while (staffChoice != 5);
}



void itemMenu(sql::Connection* con)
{
    char itemChoice;

    do
    {
        cout << "\nItem Menu:" << endl;
        cout << "1. Add new Item" << endl;
        cout << "2. Edit Item" << endl;
        cout << "3. Delete Item" << endl;
        cout << "4. Show Item" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        itemChoice = _getch() - '0';

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