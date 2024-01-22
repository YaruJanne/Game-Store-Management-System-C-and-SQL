#include "Header.h"


bool staffLogin()
{
    string enteredEmail, enteredPassword;

    cout << "+---------------------------------------------+\n";
    cout << "|                Admin Login                   |\n";
    cout << "+---------------------------------------------+\n";
    cout << "| Enter Email     | : ";
    cin >> enteredEmail;
    cout << "| Enter Password  | : ";
    cin >> enteredPassword;
    cout << "+---------------------------------------------+\n";

    // Fixed email and password for demonstration purposes
    const string fixedEmail = "jebat002@gmail.com";
    const string fixedPassword = "syai2211";

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
    system("cls");  // Clear the console screen

    do
    {
        cout << "+--------------------------+\n";
        cout << "|      Admin Main Menu     |\n";
        cout << "+--------------------------+\n";
        cout << "| 1. Item List             |\n";
        cout << "| 2. Purchase Record       |\n";
        cout << "| 3. Warranty              |\n";
        cout << "| 4. Customer              |\n";
        cout << "| 5. Sales Report          |\n";
        cout << "| 6. Exit                  |\n";
        cout << "+--------------------------+\n";
        cout << "|  Enter your choice (1-6) |\n";
        cout << "+--------------------------+\n";
        //cin >> 
        staffChoice = _getch() - '0';

        switch (staffChoice)
        {
        case 1:
            system("cls");  // Clear the console screen
            itemMenu(con);  // Go to the itemMenu
            break;
        case 2:
            system("cls");  // Clear the console screen
            purchaseRecordMenu(con);
            break;
        case 3:
            system("cls");  // Clear the console screen
            adminWarranty(con);
            break;
        case 4:
            system("cls");  // Clear the console screen
            showCustomerInfo(con);
            break;
        case 5:
            system("cls");  // Clear the console screen
            salesReport(con); // Call function for Sales Report
            break;
        case 6:
            system("cls");  // Clear the console screen
            // Returning to the main menu
            cout << "Returning to the Main Menu." << endl;
            return;  // Use return to exit the function and go back to int main
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
            break;
        }

    } while (staffChoice != 6);
}



void itemMenu(sql::Connection* con)
{
    char itemChoice;
    system("cls");  // Clear the console screen

    do
    {
        cout << "+-----------------------+\n";
        cout << "|       Item Menu       |\n";
        cout << "+-----------------------+\n";
        cout << "| 1. Add new Item       |\n";
        cout << "| 2. Edit Item          |\n";
        cout << "| 3. Delete Item        |\n";
        cout << "| 4. Show Item          |\n";
        cout << "| 5. Exit               |\n";
        cout << "+-----------------------+\n";
        cout << "|Enter your choice (1-5)|\n";
        cout << "+-----------------------+\n";
        itemChoice = _getch() - '0';

        switch (itemChoice)
        {
        case 1:
            system("cls");  // Clear the console screen

            int itemTypeChoice;
            std::cout << "+---------------------------+" << std::endl;
            std::cout << "|         Add Item          |" << std::endl;
            std::cout << "|---------------------------|" << std::endl;
            std::cout << "| 1. Physical Game          |" << std::endl;
            std::cout << "| 2. Device                 |" << std::endl;
            std::cout << "| 3. Exit to Main Menu      |" << std::endl;
            std::cout << "+---------------------------+" << std::endl;
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
            system("cls");  // Clear the console screen

            int EdititemTypeChoice;
            std::cout << "+---------------------------+" << std::endl;
            std::cout << "|         Edit Item         |" << std::endl;
            std::cout << "|---------------------------|" << std::endl;
            std::cout << "| 1. Physical Game          |" << std::endl;
            std::cout << "| 2. Device                 |" << std::endl;
            std::cout << "| 3. Exit to Main Menu      |" << std::endl;
            std::cout << "+---------------------------+" << std::endl;
            cin >> EdititemTypeChoice;

            if (EdititemTypeChoice == 1)
            {
                system("cls");  // Clear the console screen

                editPhysicalGame(con);
            }
            else if (EdititemTypeChoice == 2)
            {
                system("cls");  // Clear the console screen

                editDevice(con);
            }
            else
            {
                cout << "Invalid item type choice." << endl;
            }
            break;
        case 3:
            system("cls");  // Clear the console screen

            int DeleteitemTypeChoice;
            std::cout << "+---------------------------+" << std::endl;
            std::cout << "|        Delete Item        |" << std::endl;
            std::cout << "|---------------------------|" << std::endl;
            std::cout << "| 1. Physical Game          |" << std::endl;
            std::cout << "| 2. Device                 |" << std::endl;
            std::cout << "| 3. Exit to Main Menu      |" << std::endl;
            std::cout << "+---------------------------+" << std::endl;
            cin >> DeleteitemTypeChoice;

            if (DeleteitemTypeChoice == 1)
            {
                system("cls");  // Clear the console screen

                deletePhysicalGame(con);
            }
            else if (DeleteitemTypeChoice == 2)
            {
                system("cls");  // Clear the console screen

                deleteDevice(con);
            }
            else
            {
                system("cls");  // Clear the console screen

                cout << "Invalid item type choice." << endl;
            }
            break;
        case 4:
            system("cls");  // Clear the console screen

            int showItemTypeChoice;
            std::cout << "+---------------------------+" << std::endl;
            std::cout << "|         Show Item         |" << std::endl;
            std::cout << "|---------------------------|" << std::endl;
            std::cout << "| 1. Physical Game          |" << std::endl;
            std::cout << "| 2. Device                 |" << std::endl;
            std::cout << "| 3. Exit to Main Menu      |" << std::endl;
            std::cout << "+---------------------------+" << std::endl;
            cin >> showItemTypeChoice;

            if (showItemTypeChoice == 1)
            {
                system("cls");  // Clear the console screen

                showStaffPhysicalGames(con);
            }
            else if (showItemTypeChoice == 2)
            {
                
                system("cls");  // Clear the console screen
                showStaffDevices(con);
            }
            else
            {
                cout << "Returning to Item Menu." << endl;
            }
            break;
        case 5:
            

            cout << "Exiting Item Menu. Returning to Admin Menu." << endl;
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