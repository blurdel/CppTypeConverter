#ifndef MYDATE_H_
#define MYDATE_H_

class Date {
public:
	Date() : mYear(0), mMonth(0), mDay(0) {};
	virtual ~Date() {};

	int mYear, mMonth, mDay;
};

#endif
