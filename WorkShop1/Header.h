// Header.h

#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <iostream>
#include <iomanip>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;

// Function declarations
void itemMenu(sql::Connection* con);
void processStaff(sql::Connection* con);
void processCustomer(sql::Connection* con); 

void addNewPhysicalGame(sql::Connection* con);
void addNewDevice(sql::Connection* con);
void showPhysicalGames(sql::Connection* con);
void showDevices(sql::Connection* con);
void editPhysicalGame(sql::Connection* con);
void editDevice(sql::Connection* con);
void deletePhysicalGame(sql::Connection* con);
void deleteDevice(sql::Connection* con);
//void displayAvailableItemsWithCondition(sql::Connection* con, const string& condition, bool includeCondition);
void registerCustomer(sql::Connection* con);
bool loginCustomer(sql::Connection* con, int& customerID);
//int getNextCustomerId(sql::Connection* con);

void staffMain(sql::Connection* con);
void staffMenu(sql::Connection* con);

void addStaffRecord(sql::Connection* con);
void editStaffDetails(sql::Connection* con);
void deleteStaffRecord(sql::Connection* con);
void showStaffRecord(sql::Connection* con);

#endif
