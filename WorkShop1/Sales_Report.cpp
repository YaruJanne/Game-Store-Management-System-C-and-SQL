//Sales_Report.cpp

#include "Header.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include "Header.h"

void salesReport(sql::Connection* con)
{
    system("cls");  // Clear the console screen
    try
    {
        char productChoice;

        cout << "+---------------------------+" << endl;
        cout << "|      Sales Report         |" << endl;
        cout << "+---------------------------+" << endl;
        cout << "| 1. Physical Games         |" << endl;
        cout << "| 2. Devices                |" << endl;
        cout << "| 3. Back to Staff Main Menu|" << endl;
        cout << "+---------------------------+" << endl;
        cout << "|  Enter your choice (1-3)  |" << endl;
        cout << "+---------------------------+" << endl;
        std::cin >> productChoice;

        std::string tableName;
        std::string productName;

        // Set the table name and product name based on the user's choice
        if (productChoice == '1')
        {
            tableName = "purchasegames";
            productName = "Physical Games";
        }
        else if (productChoice == '2')
        {
            tableName = "purchasedevices";
            productName = "Devices";
        }
        else
        {
            std::cout << " Returning to the Staff Main Menu." << std::endl;
            return;
        }
        system("cls");  // Clear the console screen
        // Fetch data from the database based on the chosen product category
        std::string sqlQuery = "SELECT YEAR(Pur_Date) AS Year, MONTH(Pur_Date) AS Month, SUM(Pur_Price) AS TotalSales "
            "FROM database." + tableName + " "
            "GROUP BY YEAR(Pur_Date), MONTH(Pur_Date) "
            "ORDER BY YEAR(Pur_Date), MONTH(Pur_Date)";

        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery(sqlQuery);

        // Display the sales report
        std::cout << "\nSales Report for " << productName << ":\n";
        std::cout << "----------------------------------------------------------------\n";
        std::cout << std::setw(10) << "Year" << std::setw(10) << "Month" << std::setw(20) << "Total Sales (RM)"
            << std::setw(20) << "Percentage Change" << std::endl;
        std::cout << "----------------------------------------------------------------\n";

        double previousMonthSales = 0.0;

        while (res->next())
        {
            int year = res->getInt("Year");
            int month = res->getInt("Month");
            double totalSales = res->getDouble("TotalSales");

            std::cout << std::setw(10) << year << std::setw(10) << month << std::setw(20) << totalSales;

            // Calculate percentage change
            double percentageChange = 0.0;
            if (previousMonthSales != 0.0)
            {
                percentageChange = ((totalSales - previousMonthSales) / previousMonthSales) * 100.0;
            }

            std::cout << std::setw(20) << std::fixed << std::setprecision(2) << percentageChange << "%" << std::endl;

            // Set the total sales for the next iteration
            previousMonthSales = totalSales;
        }

       
        std::cout << "--------------------------------------------------------------\n";

        // Ask the user to return to the Staff Main Menu
        char returnToMenu;
        std::cout << "Press 'x' to return to the Staff Main Menu: ";
        std::cin >> returnToMenu;

        if (returnToMenu != 'x')
        {
            std::cout << "Invalid input. Returning to the Staff Main Menu." << std::endl;
        }
        else
        {
            std::cout << "Going back to the Staff Main Menu." << std::endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException& e)
    {
        std::cout << "SQL Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "An unexpected error occurred." << std::endl;
    }
}
