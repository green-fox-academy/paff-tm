/*
 * DataProvider.h
 *
 *  Created on: Dec 13, 2017
 *      Author: zkauker
 */

#ifndef DATAPROVIDER_H_
#define DATAPROVIDER_H_

#include <vector>
#include <string>
#include "serial/SerialPortWrapper.h"

using namespace std;

class DataProvider {
	public:
		virtual ~DataProvider();
		virtual string readNextLine() = 0;
};

class TestDataProvider: public DataProvider {
	public:
		TestDataProvider();
		string readNextLine();
	private:
		vector<string> _testData;
		int _currentIdx;
		time_t _lastDataSent;
};

class SerialDataProvider: public DataProvider {
	public:
		SerialDataProvider(string portName, int baudRate);
		~SerialDataProvider();
		string readNextLine();
	private:
		SerialPortWrapper *_serialPort;
		bool _isOpen;
};

#endif /* DATAPROVIDER_H_ */
