//============================================================================
// Name        : TemperatureLoggerCA.cpp
// Author      : Z
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

#include "util.h"
#include "Common.h"
#include "DataProvider.h"
#include "TemperatureLogger.h"

using namespace std;

int main() {

	SerialDataProvider sdp("tty.usbmodem1413", 115200);

	//TestDataProvider tdp;
	TemperatureLogger logger(&sdp);

	logger.banner();
	cout << endl;
	logger.help();

	string command;
	getline(cin, command);

	do {
		if (command == CMD_HELP) {
			logger.help();
		}
		else if (command == CMD_LIST) {
			logger.list();
		}
		else if (command == CMD_START_STOP) {
			logger.start();
		}
		else if (command == CMD_FILE_WRITE) {
			logger.fileWrite();
		}
		else if (command == CMD_FILE_READ) {
			logger.fileRead();
		}
		else if (command == CMD_MIN) {
			logger.minimum();
		}
		else if (command == CMD_MAX) {
			logger.maximum();
		}
		else if (command == CMD_AVG) {
			logger.average();
		}
		else {
			cerr << "ERROR: unknown command: " << command << endl;
		}

		getline(cin, command);
	}
	while (command != CMD_EXIT);

	cout << "Bye!" << endl;

	return 0;
}
