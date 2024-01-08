//Order.cpp

#include "Header.h"

void orderMenu(sql::Connection* con);  

void orderMenu(sql::Connection* con)
{
    int orderChoice;

    do
    {
        cout << "\nOrder Menu:" << endl;
        cout << "1. Order" << endl;
        cout << "2. Show Order" << endl;
        cout << "3. Exit to Customer Menu" << endl;
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> orderChoice;

        switch (orderChoice)
        {
        case 1:
            // Order new items
            // Implement logic to interact with the purchase record in the database
            // You can create a function for this, e.g., orderNewItems(con, customerEmail);
            break;
        case 2:
            // Show existing orders
            // Implement logic to display the purchase record from the database
            // You can create a function for this, e.g., showOrder(con, customerEmail);
            break;
        case 3:
            cout << "Exiting to Customer Menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
            break;
        }

        // Check if the user pressed 'x' to return to the Order menu
        char returnToMenu;
        cout << "Press 'x' to return to the Customer Menu: ";
        cin >> returnToMenu;

        if (returnToMenu != 'x')
        {
            cout << "Invalid input. Returning to the Order menu." << endl;
        }
        else
        {
            cout << "Going back to Customer Menu." << endl;
        }
    } while (orderChoice != 3);  // Repeat the loop until the user chooses to exit
}

// Implement the orderNewItems and showOrder functions as needed