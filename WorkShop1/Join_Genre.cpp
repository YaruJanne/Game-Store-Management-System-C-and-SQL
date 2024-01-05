// Join_Genre.cpp

#include "Header.h"
/*
void searchItemsByCondition(sql::Connection* con) {
    int searchChoice;
    string condition;
    bool includeCondition;

    do {
        cout << "\nSearch Items by Condition:\n";
        cout << "1. Search by ID\n";
        cout << "2. Search by Name\n";
        cout << "3. Search by Condition\n";
        cout << "4. Search by Price\n";
        cout << "5. Back to Customer Menu\n";
        cout << "Enter your choice (1-5): ";
        cin >> searchChoice;

        switch (searchChoice) {
        case 1:
            condition = "List_ID";
            break;
        case 2:
            condition = "Item_Name";
            break;
        case 3:
            condition = "Item_Condition";
            break;
        case 4:
            condition = "Item_Price";
            break;
        case 5:
            cout << "Returning to Customer Menu.\n";
            return;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
            continue;
        }

        char includeChoice;
        cout << "Include this condition? (Y/N): ";
        cin >> includeChoice;

        includeCondition = (includeChoice == 'Y' || includeChoice == 'y');

        if (includeCondition) {
            cout << "Enter the detail for " << condition << ": ";
            cin.ignore();
            getline(cin, condition);
        }

  void displayAvailableItemsWithCondition(con, condition, includeCondition);

        char retryChoice;
        cout << "\nDo you want to search again? (Y/N): ";
        cin >> retryChoice;

        if (retryChoice != 'Y' && retryChoice != 'y') {
            cout << "Returning to Customer Menu.\n";
            return;
        }

    } while (true);
}
*/