#pragma once
#include <stdlib.h>
#include <iostream>
#include <iomanip>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

using namespace std;

void processStaff(sql::Connection* con); 
void addNewPhysicalGame(sql::Connection* con);
void addNewDevice(sql::Connection* con);
void showPhysicalGames(sql::Connection* con);
void showDevices(sql::Connection* con);
void editPhysicalGame(sql::Connection* con);
void editDevice(sql::Connection* con);
void deletePhysicalGame(sql::Connection* con);
void deleteDevice(sql::Connection* con);
void processCustomer(sql::Connection* con, int choice); 


