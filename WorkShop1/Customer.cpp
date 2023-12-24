#include "Header.h"

void processCustomer(sql::Connection* con, int choice)
{
    int customerChoice;

    do
    {
        std::cout << "\nCustomer Menu:" << std::endl;
        std::cout << "1. Physical Game" << std::endl;
        std::cout << "2. Device" << std::endl;
        std::cout << "3. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice (1, 2, or 3): ";
        std::cin >> customerChoice;

        switch (customerChoice)
        {
        case 1:
            showPhysicalGames(con);
            break;
        case 2:
            showDevices(con);
            break;
        case 3:
            int choice;  // Declare the choice variable here

            cout << "\nWelcome to the Game Store!" << endl;
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
            std::cout << "Invalid choice. Please enter 1, 2, or 3." << std::endl;
            break;
        }

        // Check if the user pressed 'x' to return to the Customer menu
        if (customerChoice != 3)
        {
            char returnToMenu;
            cout << "Press 'x' to return to the Customer menu: ";
            cin >> returnToMenu;

            if (returnToMenu != 'x')
            {
                cout << "Invalid input. Returning to the Customer menu." << endl;
                processCustomer(con, choice);  // Pass the choice variable when calling recursively
            }
        }
    } while (customerChoice != 3);

    // Additional customer functionality can be implemented here
    // For example, making orders, viewing details of specific items, etc.
    std::cout << "Customer functionality coming soon!" << std::endl;
}