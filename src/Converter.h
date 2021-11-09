#ifndef CONVERTER_H_
#define CONVERTER_H_

#include "IConverter.h"


template <typename S, typename T>
class Converter : public IConverter {
public:
	Converter() {};
	virtual ~Converter() {};


	virtual T convert(S) = 0;

};

#endif
