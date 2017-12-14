/*
 * CumulatedCalculator.cpp
 *
 *  Created on: Dec 13, 2017
 *      Author: zkauker
 */
#include <iostream>
#include <numeric>
#include "CumulatedCalculator.h"

using namespace std;

CumulatedCalculator::~CumulatedCalculator() {};

void MinimumCalculator::calculateAndPrint(vector<util::temperature_record> records) {
	vector<util::temperature_record>::iterator it = min_element(records.begin(), records.end(), util::compareByTemperature);
	util::temperature_record tr = *it;
	cout << "\tResult: " << tr.temperature << endl;
};

void MaximumCalculator::calculateAndPrint(vector<util::temperature_record> records) {
	vector<util::temperature_record>::iterator it = max_element(records.begin(), records.end(), util::compareByTemperature);
	util::temperature_record tr = *it;
	cout << "\tResult: " << tr.temperature << endl;
};

void AverageCalculator::calculateAndPrint(vector<util::temperature_record> records) {
	float sum = 0;
	for (int i = 0; i < records.size(); i++) {
		sum += records.at(i).temperature;
	}
	cout << "\tAverage: " << (sum/records.size()) << endl;
};
