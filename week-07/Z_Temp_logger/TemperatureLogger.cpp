/*
 * TemperatureLogger.cpp
 *
 *  Created on: Dec 13, 2017
 *      Author: zkauker
 */

#include "TemperatureLogger.h"
#include "Common.h"
#include <iostream>
#include <sstream>
#include <fstream>

TemperatureLogger::TemperatureLogger(DataProvider *provider) :
		_provider(provider) {
}
;

TemperatureLogger::time_range TemperatureLogger::_readCumulationParameters() {
	std::cout << "Please specify your time window with one of the following formats:" << std::endl;
	std::cout << "\t1 yyyy.MM.dd\t\ta specific day" << std::endl;
	std::cout << "\t2 N\t\t\tthe last N days" << std::endl;
	std::cout << "\t3 yyyy.MM.dd yyyy.MM.dd\tfrom specific day to specific day (inclusive)" << std::endl;

	string params;
	getline(cin, params);

	istringstream paramsStream(params);
	int mode;
	paramsStream >> mode;
	if (paramsStream.fail()) {
		throw new util::ParserException(900, "ERROR: invalid parameters!");
	}

	tm start, end;
	time_t start_ts, end_ts = 0;
	switch (mode) {
		case 1:
			start = util::readNextDate(paramsStream);

			start_ts = mktime(&start);
			end_ts = start_ts + SECONDS_IN_DAYS;
			break;
		case 2:
			int noDays;
			paramsStream >> noDays;
			if (paramsStream.fail()) {
				throw new util::ParserException(902, "ERROR: No valid number found after mode 2!");
			}

			end_ts = time(NULL);
			start_ts = end_ts - noDays * SECONDS_IN_DAYS;
			break;
		case 3:
			start = util::readNextDate(paramsStream);
			end = util::readNextDate(paramsStream);

			start_ts = mktime(&start);
			end_ts = mktime(&end);
			break;
		default:
			throw new util::ParserException(905, "ERROR: invalid mode!");
	}
	TemperatureLogger::time_range range(start_ts, end_ts);
	return range;
}
;

void TemperatureLogger::_cumulatedCalculation(CumulatedCalculator *calc) {
	if (_records.empty()) {
		cerr << "ERROR: There's no record to process!" << endl;
		return;
	}

	try {
		TemperatureLogger::time_range range = _readCumulationParameters();
		vector<util::temperature_record> filteredRecords;
		for (int i = 0; i < _records.size(); i++) {
			util::temperature_record aRec = _records.at(i);
			if (aRec.timestamp < range.start || aRec.timestamp > range.end) {
				continue;
			}
			filteredRecords.push_back(aRec);
		}

		if (filteredRecords.empty()) {
			cout << "\tNo record matches to the specified criteria (min: " << range.start << ", max: " << range.end << ")!" << endl;
			return;
		}

		// we have start and end time, so let's filter our records and print the results!
		calc->calculateAndPrint(filteredRecords);
	}
	catch (util::ParserException *exception) {
		cerr << "ERROR: error in parameters: " << exception->getMessage() << endl;
		return;
	}
}
;

void TemperatureLogger::minimum() {
	_cumulatedCalculation(&_minCalc);
}
;

void TemperatureLogger::maximum() {
	_cumulatedCalculation(&_maxCalc);
}
;

void TemperatureLogger::average() {
	_cumulatedCalculation(&_avgCalc);
}
;

void TemperatureLogger::fileWrite() {
	if (_records.size() == 0) {
		cerr << "WARNING: There's no data to save!" << endl;
		return;
	}
	ofstream destFile(FILE_STORE);
	if (!destFile.is_open()) {
		cerr << "ERROR: Could not open file for writing: " << FILE_STORE << endl;
		return;
	}

	for (int i = 0; i < _records.size(); i++) {
		util::temperature_record rec = _records.at(i);
		destFile << rec.timestamp << "\t" << rec.temperature << endl;
	}

	destFile.close();
}
;

void TemperatureLogger::fileRead() {
	ifstream sourceFile(FILE_STORE);

	if (!sourceFile.is_open()) {
		cerr << "ERROR: Could not open file for reading: " << FILE_STORE << endl;
		return;
	}

	do {
		time_t ts;
		int temp;
		sourceFile >> ts >> temp;
		if (sourceFile.fail()) {
			continue;
		}
		util::temperature_record rec(temp, ts);
		_records.push_back(rec);
	}
	while (!sourceFile.eof());

	sourceFile.close();
}
;

void TemperatureLogger::start() {
	cout << "OK, i'm starting to read records, to stop use " << CMD_START_STOP << " command" << endl;
	string input;
	do {
		if (util::isInputAvailable()) {
			getline(cin, input);
			continue;
		}

		string nextLine = _provider->readNextLine();
		if (nextLine.empty()) {
			continue;
		}
		try {
			util::temperature_record newRecord = util::parseLine(nextLine);
			_records.push_back(newRecord);
		}
		catch (util::ParserException *ex) {
			cerr << "ERROR while trying to process line: " << nextLine << ", message: " << ex->getMessage() << endl;
		}

	}
	while (input != CMD_START_STOP);
	cout << "OK, current records count: " << _records.size() << endl;
}

void TemperatureLogger::list() {
	cout << "Records (count: " << _records.size() << "): [" << endl;
	for (int i = 0; i < _records.size(); i++) {
		util::temperature_record aRecord = _records.at(i);
		cout << "\ttemperature_record(timestamp=" << aRecord.timestamp << ", temperature=" << aRecord.temperature << ")" << endl;
	}
	cout << "]" << endl;
}

void TemperatureLogger::help() {
	cout << "Temperature Logger Application" << endl;
	cout << "==============================" << endl;
	cout << "Commands:" << endl;
	cout << " " << CMD_HELP << "        Show command list" << endl;
	cout << " " << CMD_START_STOP << "        Start logging / Stop logging" << endl;
	cout << " " << CMD_LIST << "        List after error handling" << endl;
	cout << " " << CMD_FILE_WRITE << "        Store data in file" << endl;
	cout << " " << CMD_FILE_READ << "        Read data from file" << endl;
	cout << " " << CMD_MIN << "      Calculate minimum" << endl;
	cout << " " << CMD_MAX << "      Calculate maximum" << endl;
	cout << " " << CMD_AVG << "      Calculate average" << endl;
	cout << " " << CMD_EXIT << "        Exit from the program" << endl;
}

void TemperatureLogger::banner() {
	cout << "___________                                        __                        " << endl;
	cout << "\\__    ___/___   _____ ______   ________________ _/  |_ __ _________   ____  " << endl;
	cout << "  |    |_/ __ \\ /     \\\\____ \\_/ __ \\_  __ \\__  \\\\   __\\  |  \\_  __ \\_/ __ \\ " << endl;
	cout << "  |    |\\  ___/|  Y Y  \\  |_> >  ___/|  | \\// __ \\|  | |  |  /|  | \\/\\  ___/ " << endl;
	cout << "  |____| \\___  >__|_|  /   __/ \\___  >__|  (____  /__| |____/ |__|    \\___  >" << endl;
	cout << "             \\/      \\/|__|        \\/           \\/                        \\/ " << endl;
	cout << "              .____                                                          " << endl;
	cout << "              |    |    ____   ____   ____   ___________                     " << endl;
	cout << "              |    |   /  _ \\ / ___\\ / ___\\_/ __ \\_  __ \\                    " << endl;
	cout << "              |    |__(  <_> ) /_/  > /_/  >  ___/|  | \\/                    " << endl;
	cout << "              |_______ \\____/\\___  /\\___  / \\___  >__|                       " << endl;
	cout << "                      \\/    /_____//_____/      \\/                           " << endl;
}
