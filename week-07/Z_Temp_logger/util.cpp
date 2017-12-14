#include <iostream>
#include <sstream>
#include <limits>
#include "util.h"

/**
 * implementation of our utility collection
 */
namespace util {

	void _checkRange(int number, int min, int max);

	/**
	 * Here comes the implementation of our custom exception. Nothing special: constructor,
	 * the required destructor with empty implementation, getters for the code and message
	 * fields, the required what() implementation and it's done.
	 */
	ParserException::ParserException(int code, std::string message) :
			_code(code), _message(message) {
	}
	;
	ParserException::~ParserException() _NOEXCEPT {
	}
	;
	int ParserException::getCode() {
		return _code;
	}
	;
	std::string ParserException::getMessage() {
		return _message;
	}
	;
	const char* ParserException::what() const _NOEXCEPT {
		std::ostringstream res;
		res << "ParserException(code=" << _code << ",message=" << _message
				<< ")";
		return res.str().c_str();
	}
	;

	/**
	 * This is our function, which does the logic. The beginning should be familiar!
	 */
	temperature_record parseLine(std::string line) {

		// let's do this with streams!
		std::istringstream line_stream(line);

		// read the date and time
		tm t = readNextDate(line_stream, true);

		// read the temperature
		int temperature;
		line_stream >> temperature;

		if (line_stream.fail()) {
			throw new ParserException(1, "Unsupported string format!");
		}

		// we've successfully read the numbers, let's check the temperature
		if (temperature < -273 || temperature > 1000) {
			throw new ParserException(2, "Temperature is out of range!");
		}

		// let's try to calculate the timestamp
		time_t timestamp = mktime(&t);
		if (timestamp < 0) {
			throw new ParserException(4,
					"Could not create timestamp based on the given data!");
		}

		// now the date and time is OK as well, so let's return the data
		return temperature_record(temperature, timestamp);
	}
	;

	tm readNextDate(std::istream &stream, bool withTime) {
		int year, month, day;
		char sep;

		// get the date
		stream >> year >> sep >> month >> sep >> day;

		// throw error if something went wrong
		if (stream.fail()) {
			throw new ParserException(1, "Unsupported string format!");
		}

		// if the time should be readed as well, let's do it!
		int hour = 0, minute = 0, second = 0;
		if (withTime) {
			stream >> hour >> sep >> minute >> sep >> second;
			if (stream.fail()) {
				throw new ParserException(1, "Unsupported string format!");
			}
		}
		// try to pack it, will throw exception if it will be unsuccessful
		return packDateTime(year, month, day, hour, minute, second);
	};

	/**
	 * Validates the date and creates a tm structure
	 */
	tm packDateTime(int year, int month, int day, int hour, int minute,
			int second) {
		// validating date - checking the month
		_checkRange(month, 1, 12);

		// let's check what is the day limit in that month
		int monthDayMax = _MONTH_DAYS[month - 1];

		// the evil feb. 29: https://en.wikipedia.org/wiki/February_29
		if (month == 2) {
			if (!year % 4) {
				if (year % 100 || !year % 400) {
					monthDayMax = 29;
				}
			}
		}
		_checkRange(day, 1, monthDayMax);

		// Date is OK, checking time
		_checkRange(hour, 0, 23);
		_checkRange(minute, 0, 59);
		_checkRange(second, 0, 59);

		// Time is OK, packing tm structure manually. Ref: http://www.cplusplus.com/reference/ctime/tm/
		tm t;
		t.tm_sec = second;
		t.tm_min = minute;
		t.tm_hour = hour;
		t.tm_mday = day;
		t.tm_mon = month - 1;
		t.tm_year = year - 1900;

		return t;
	}
	;

	/**
	 * A helper function, which throws our exception if the 1st argument is out of the specified
	 * range of 2nd and 3rd (min and max) arguments.
	 */
	void _checkRange(int number, int min, int max) {
		if (number < min || number > max) {
			throw new ParserException(3, "Checked number is out of range!");
		}
	}

	int compareByTemperature(util::temperature_record one,
			util::temperature_record other) {
		return one.temperature < other.temperature;
	}

	bool isInputAvailable() {
		struct timeval tv;
		fd_set fds;
		tv.tv_sec = 0;
		tv.tv_usec = 0;
		FD_ZERO(&fds);
		FD_SET(STDIN_FILENO, &fds);
		select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv);
		return (FD_ISSET(0, &fds));
	}
}
;
