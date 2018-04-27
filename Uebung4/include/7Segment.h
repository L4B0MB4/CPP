#include <iostream>
#include "PreAllocString.h"
#include <stdarg.h>

template <typename ... Args>
class MultiDigit {

public:
	constexpr MultiDigit(Args ... args)
	{
		test(args...);
	}
	template<typename T, typename ... PArgs>
	constexpr T test(T first, PArgs ... args)
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

	 operator const char *()  const
	{
		return nullptr;
	}

};