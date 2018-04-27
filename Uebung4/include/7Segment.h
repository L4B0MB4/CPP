#include <iostream>
#include "PreAllocString.h"
#include <stdarg.h>

class MultiDigit {

public:
	template<typename ... Args>
	constexpr MultiDigit(Args ... args)
	{
		test(args...);
	}
	template<typename T, typename ... Args>
	constexpr T test(T first, Args ... args)
	{
		//printf("hiiier %d \n",first);
		test(args...);
		return first;
	}
	template<typename T>
	constexpr T test(T first) {
		return first;
		//printf("hiiier %d \n",first);
	}

};