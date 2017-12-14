/*
 * TemperatureLogger.h
 *
 *  Created on: Dec 13, 2017
 *      Author: zkauker
 */

#ifndef TEMPERATURELOGGER_H_
#define TEMPERATURELOGGER_H_

#include <vector>
#include "util.h"

#include "DataProvider.h"
#include "CumulatedCalculator.h"

using namespace std;

class TemperatureLogger {
	public:
		TemperatureLogger(DataProvider *provider);
		void banner();
		void help();
		void start();
		void list();
		void fileWrite();
		void fileRead();
		void minimum();
		void maximum();
		void average();
	private:

		struct time_range {
			time_t start;
			time_t end;
			time_range(time_t start, time_t end): start(start), end(end) {};
		};

		DataProvider *_provider;
		vector<util::temperature_record> _records;

		MinimumCalculator _minCalc;
		MaximumCalculator _maxCalc;
		AverageCalculator _avgCalc;

		time_range _readCumulationParameters();
		void _cumulatedCalculation(CumulatedCalculator *calculator);
};


#endif /* TEMPERATURELOGGER_H_ */
