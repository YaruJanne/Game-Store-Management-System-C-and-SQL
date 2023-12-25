#include "Header.h"

void displayAvailableItemsWithCondition(sql::Connection* con, const string& condition)
{
    try
    {
        con->setSchema("database");

        // Perform a join between PhysicalGames and Devices based on Item_Condition
        string query = "SELECT * FROM PhysicalGames INNER JOIN Devices ON PhysicalGames.Item_Condition = Devices.Item_Condition WHERE PhysicalGames.Item_Condition = ?";

        sql::PreparedStatement* pstmt = con->prepareStatement(query);
        pstmt->setString(1, condition);

        sql::ResultSet* res = pstmt->executeQuery();

        cout << "Items with Condition '" << condition << "':" << endl;
        cout << "List_ID\tItem_Name\tItem_Quantity\tItem_Condition\tItem_Price\tItem_Date" << endl;

        while (res->next())
        {
            cout << res->getInt("List_ID") << "\t" << res->getString("Item_Name") << "\t"
                << res->getInt("Item_Quantity") << "\t" << res->getString("Item_Condition") << "\t"
                << res->getDouble("Item_Price") << "\t" << res->getString("Item_Date") << endl;
        }

        delete res;
        delete pstmt;
    }
    catch (sql::SQLException e)
    {
        cout << "Error fetching items with condition. Error message: " << e.what() << endl;
    }
}