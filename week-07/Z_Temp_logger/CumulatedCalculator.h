/*
 * CumulatedCalculator.h
 *
 *  Created on: Dec 13, 2017
 *      Author: zkauker
 */

#ifndef CUMULATEDCALCULATOR_H_
#define CUMULATEDCALCULATOR_H_

#include <vector>
#include "util.h"

using namespace std;

class CumulatedCalculator {
	public:
		virtual ~CumulatedCalculator();
		virtual void calculateAndPrint(vector<util::temperature_record> records) = 0;
};

class MinimumCalculator: public CumulatedCalculator {
	public:
		void calculateAndPrint(vector<util::temperature_record> records);
};

class MaximumCalculator: public CumulatedCalculator {
	public:
		void calculateAndPrint(vector<util::temperature_record> records);
};

class AverageCalculator: public CumulatedCalculator {
	public:
		void calculateAndPrint(vector<util::temperature_record> records);
};

#endif /* CUMULATEDCALCULATOR_H_ */
