#include"Header.h"

void displayAvailableItems(sql::Connection* con, const string& itemType)
{
    try
    {
        con->setSchema("database");

        sql::Statement* stmt = con->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM " + itemType);

        cout << "Available " << itemType << ":" << endl;
        cout << "ID\tName\tQuantity" << endl;

        while (res->next())
        {
            cout << res->getInt("id") << "\t" << res->getString("name") << "\t" << res->getInt("quantity") << endl;
        }

        delete res;
        delete stmt;
    }
    catch (sql::SQLException e)
    {
        cout << "Error fetching available items. Error message: " << e.what() << endl;
    }
}

void createTableIfNotExists(sql::Connection* con, const string& itemType)
{
    try
    {
        con->setSchema("database");

        sql::Statement* stmt = con->createStatement();
        stmt->execute("CREATE TABLE IF NOT EXISTS " + itemType + " (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);");
        cout << itemType << " table created (if not existed)." << endl;
        delete stmt;

        // Insert sample items into the table
        insertSampleItems(con, itemType);
    }
    catch (sql::SQLException e)
    {
        cout << "Error creating " << itemType << " table. Error message: " << e.what() << endl;
    }
}

void insertSampleItems(sql::Connection* con, const string& itemType)
{
    try
    {
        con->setSchema("database");

        sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO " + itemType + "(name, quantity) VALUES(?,?)");

        pstmt->setString(1, "SampleItem1");
        pstmt->setInt(2, 10);
        pstmt->execute();

        pstmt->setString(1, "SampleItem2");
        pstmt->setInt(2, 15);
        pstmt->execute();

        pstmt->setString(1, "SampleItem3");
        pstmt->setInt(2, 20);
        pstmt->execute();

        delete pstmt;
    }
    catch (sql::SQLException e)
    {
        cout << "Error inserting sample items into " << itemType << ". Error message: " << e.what() << endl;
    }
}

void processCustomer(sql::Connection* con)
{
    int customerChoice;

    do
    {
        cout << "Customer Menu:" << endl;
        cout << "1. Devices" << endl;
        cout << "2. Physical" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> customerChoice;

        switch (customerChoice)
        {
        case 1:
            createTableIfNotExists(con, "Devices");
            displayAvailableItems(con, "Devices");
            break;
        case 2:
            createTableIfNotExists(con, "Physical");
            displayAvailableItems(con, "Physical");
            break;
        case 3:
            cout << "Exiting customer menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
            break;
        }
    } while (customerChoice != 3);

    // Implement additional customer functionality here
    // For example, making orders, viewing details of specific items, etc.
    cout << "Customer functionality coming soon!" << endl;
}