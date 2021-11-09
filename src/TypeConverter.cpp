#include <iostream>
#include <string>
using namespace std;

#include "Converter.h"
#include "DateConverter.h"
#include "Date.h"


int main() {
	cout << "Type Converter" << endl;


	DateConverter<string, Date> dc1;
	Date d1 = dc1.convert("2001/05/13");
	cout << d1.mYear << "-" << d1.mMonth << "-" << d1.mDay << endl;


	Converter<string, Date>* conv = new DateConverter<string, Date>();
	Date date = conv->convert("2021-10-20");
	cout << date.mYear << "-" << date.mMonth << "-" << date.mDay << endl;
	if (conv) {
		delete conv;
		conv = nullptr;
	}

//	std::shared_ptr<int> my_ptr{ new int{ 808 } };


	IConverter* ic = new DateConverter<string, Date>();
	DateConverter<string, Date>* pDC = dynamic_cast<DateConverter<string, Date>*>(ic);
	if (pDC != nullptr) {
		cout << typeid(*pDC).name() << endl;
		Date dd = pDC->convert("19991231");
		cout << dd.mYear << "-" << dd.mMonth << "-" << dd.mDay << endl;
	}
	if (ic) {
		delete ic;
		ic = nullptr;
	}
	if (pDC) {
		// delete pDC;
		pDC = nullptr;
	}


	DateConverter<string, Date> dc2;
	Date d2 = dc2.convert("2000 01 01");
	cout << d2.mYear << "-" << d2.mMonth << "-" << d2.mDay << endl;


	return 0;
}
