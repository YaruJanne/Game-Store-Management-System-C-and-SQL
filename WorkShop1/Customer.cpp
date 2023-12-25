75
#include "Header.h"


void processCustomer(sql::Connection* con, int choice)
{
    int customerChoice = 0;  // Initialize the variable to avoid the error

    do
    {
        cout << "Customer Menu:" << endl;
        cout << "1. Physical Game" << endl;
        cout << "2. Device" << endl;
        cout << "3. Search Items by Condition" << endl;
        cout << "4. Exit to Main Menu" << endl;
        cout << "Enter your choice (1, 2, 3, or 4): ";
        cin >> customerChoice;

        switch (customerChoice)
        {
        case 1:
            showPhysicalGames(con);
            break;
        case 2:
            showDevices(con);
            break;
        case 3:
            string condition;
            cout << "Enter the condition to search for: ";
            cin.ignore();
            getline(cin, condition);

            displayAvailableItemsWithCondition(con, condition);
            break;
            return;
        case 4:
            cout << "Exiting to Main Menu." << endl;
            break;  // Return from the function to go back to the main menu
        default:
            cout << "Invalid choice. Please enter 1, 2, 3, or 4." << endl;
            break;
        }

        // Check if the user pressed 'x' to return to the Customer menu
        char returnToMenu;
        cout << "Press 'x' to return to the Main Menu: ";
        cin >> returnToMenu;

        if (returnToMenu != 'x')
        {
            cout << "Invalid input. Returning to the Customer menu." << endl;
        }
        else
        {
            cout << "Going back to Main Menu." << endl;
            return;  // Return from the function to go back to the main menu
        }
    }while (customerChoice != 4);  // Repeat the loop until the user chooses to exit

}