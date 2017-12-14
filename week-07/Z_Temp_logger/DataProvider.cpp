/*
 * DataProvider.cpp
 *
 *  Created on: Dec 13, 2017
 *      Author: zkauker
 */
#include "DataProvider.h"

DataProvider::~DataProvider() {};

TestDataProvider::TestDataProvider() {
	_testData.push_back("2015.1.3 13:44:1\t19");
	_testData.push_back("2015.1.4 13:44:1\t25");
	_testData.push_back("2015.1.5 13:44:1\t42");
	_testData.push_back("2015.1.6 13:44:1\t10");
	_testData.push_back("2015.1.7 13:44:1\t-10");
	_testData.push_back("2015.1.8 13:44:1\t70");
	_testData.push_back("2015.1.9 13:44:1\t1901230");
	_testData.push_back("20fókatelep1\t19");
	_testData.push_back("2013:44:1\t19");
	_testData.push_back("2015.1.3 13:44:1\t19");
	_testData.push_back("3010.3 13:72:1\t19");
	_testData.push_back("201.1.3 25:44:1\t19");
	_testData.push_back("2015.2.30 13:44:1\t19");
	_testData.push_back("2015.13.3 13:44:1\t19");
	_currentIdx = 0;
	_lastDataSent = 0;
};

string TestDataProvider::readNextLine() {
	if (_currentIdx == _testData.size()) {
		_currentIdx = 0;
	}
	time_t now = time(NULL);
	if ((now-_lastDataSent) < 1) {
		return "";
	}
	_lastDataSent = now;
	return _testData.at(_currentIdx++);
};

SerialDataProvider::SerialDataProvider(string portName, int baudRate) {
	_serialPort = new SerialPortWrapper(portName, baudRate);
	_isOpen = false;
};

SerialDataProvider::~SerialDataProvider() {
	if (_isOpen) {
		_serialPort->closePort();
	}
	delete _serialPort;
};

string SerialDataProvider::readNextLine() {
	if (!_isOpen) {
		_serialPort->openPort();
		_isOpen = true;
	}
	string result;
	_serialPort->readLineFromPort(&result);
	return result;
};

