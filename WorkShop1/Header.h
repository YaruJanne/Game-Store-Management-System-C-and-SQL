// Header.h

#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>

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
void registerCustomer(sql::Connection* con);
bool loginCustomer(sql::Connection* con, int& customerId);
void staffMain(sql::Connection* con);
void staffMenu(sql::Connection* con);

//purchase 
void orderMenu(sql::Connection* con);
void orderNewItems(sql::Connection* con, const string& customerEmail);
void showOrder(sql::Connection* con, const string& customerEmail);



void addStaffRecord(sql::Connection* con);
void editStaffDetails(sql::Connection* con);
void deleteStaffRecord(sql::Connection* con);
void showStaffRecord(sql::Connection* con);




#endif
