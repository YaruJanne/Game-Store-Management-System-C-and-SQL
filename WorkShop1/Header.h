// Header.h

#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <conio.h>
#include <string>
#include <cmath>



#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#pragma warning(disable : 26495)

using namespace std;

// Function declarations
void itemMenu(sql::Connection* con);
void processStaff(sql::Connection* con);
void processCustomer(sql::Connection* con);
void enterCustomer(sql::Connection* con);
void addNewPhysicalGame(sql::Connection* con);
void addNewDevice(sql::Connection* con);
void showPhysicalGames(sql::Connection* con);
void showDevices(sql::Connection* con);
void editPhysicalGame(sql::Connection* con);
void editDevice(sql::Connection* con);
void deletePhysicalGame(sql::Connection* con);
void deleteDevice(sql::Connection* con);
void displayAvailableItemsWithCondition(sql::Connection* con, const string& condition, bool includeCondition);
void RegisterCustomer(sql::Connection* con);
bool loginCustomer(sql::Connection* con, int& customerId);
void staffMain(sql::Connection* con);
void staffMenu(sql::Connection* con);

//Order
void orderMenu(sql::Connection* con);
void orderNewGames(sql::Connection* con);
void orderNewDevice(sql::Connection* con);
void showOrder(sql::Connection* con, const string& customerEmail);
void printReceiptToFileGames(sql::ResultSet* res, sql::Connection* con);
void printReceiptToFileDevices(sql::ResultSet* res, sql::Connection* con);
// staff
void addStaffRecord(sql::Connection* con);
void editStaffDetails(sql::Connection* con);
void deleteStaffRecord(sql::Connection* con);
void showStaffRecord(sql::Connection* con);
//Staff_Order
void purchaseRecordMenu(sql::Connection* con);
void showPurchaseGames(sql::Connection* con);
void showPurchaseDevices(sql::Connection* con);
//Staff_Warranty
void adminWarranty(sql::Connection* con);
void showWarrantyGames(sql::Connection* con);
void showWarrantyDevices(sql::Connection* con);
//Staff_Customer
void showCustomerInfo(sql::Connection* con);
//Sales_Report
void salesReport(sql::Connection* con);
//Staff_Show
void showStaffPhysicalGames(sql::Connection* con);
void showStaffDevices(sql::Connection* con);



#endif