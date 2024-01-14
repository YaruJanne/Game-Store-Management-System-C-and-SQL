//Staff_Show

#include "Header.h"

void showStaffPhysicalGames(sql::Connection* con)
{
    system("cls");  // Clear the console screen

    try
    {
        con->setSchema("database");

        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM PhysicalGames");

        cout << "Physical Games" << endl;
        cout << "\n" << left << setw(14) << "Games ID" << setw(35) << "Item Name" << setw(18) << "Item Quantity"
            << setw(18) << "Item Condition" << setw(18) << "Item Price" << setw(18) << "Item Date" << endl;

        while (res->next())
        {
            cout << left << setw(14) << res->getInt("Games_List_ID") << setw(35) << res->getString("Item_Name")
                << setw(18) << res->getInt("Item_Quantity") << setw(18) << res->getString("Item_Condition")
                << setw(18) << res->getDouble("Item_Price") << setw(18) << res->getString("Item_Date") << endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException e)
    {
        cout << "Error fetching Physical Games. Error message: " << e.what() << endl;
    }
}

void showStaffDevices(sql::Connection* con)
{
    system("cls");  // Clear the console screen

    try
    {
        con->setSchema("database");

        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM Devices");

        cout << "Devices" << endl;
        cout << "\n" << left << setw(14) << "Devices ID" << setw(35) << "Item Name" << setw(18) << "Item Quantity"
            << setw(18) << "Item Condition" << setw(18) << "Item Price" << setw(18) << "Item Date" << endl;

        while (res->next())
        {
            cout << left << setw(14) << res->getInt("Devices_List_ID") << setw(35) << res->getString("Item_Name")
                << setw(18) << res->getInt("Item_Quantity") << setw(18) << res->getString("Item_Condition")
                << setw(18) << res->getDouble("Item_Price") << setw(18) << res->getString("Item_Date") << endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException e)
    {
        cout << "Error fetching Devices. Error message: " << e.what() << endl;
    }
}
