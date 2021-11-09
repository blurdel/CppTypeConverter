#ifndef DATECONVERTER_H_
#define DATECONVERTER_H_

#include <string>
#include <regex>
#include "Converter.h"
#include "Date.h"


template <typename S, typename T>
//class DateConverter : public Converter<std::string, Date> {
class DateConverter : public Converter<S, T> {
public:
	DateConverter() {};
	virtual ~DateConverter() {};

	virtual Date convert(std::string pDate) override {
		Date date;

		// 2021-10-18, 2021/10/18
		pDate = std::regex_replace(pDate, std::regex("-"), "");
		pDate = std::regex_replace(pDate, std::regex("/"), "");
		pDate = std::regex_replace(pDate, std::regex(" "), "");

		if (pDate.length() == 8) {
			// 20211018
			date.mYear = std::atoi(pDate.substr(0, 4).c_str());
			date.mMonth = std::atoi(pDate.substr(4, 2).c_str());
			date.mDay = std::atoi(pDate.substr(6, 2).c_str());
		}
		return date;
	}

};

#endif
