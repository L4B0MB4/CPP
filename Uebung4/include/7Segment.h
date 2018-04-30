#include <iostream>
#include "PreAllocString.h"
#include <stdarg.h>
#define MAX_DIGITS 10

template <typename ... Args>
class MultiDigit {

public:
	constexpr MultiDigit(Args ... args)
	{
		string.Empty();
		for(lH=0;lH<5;lH++)
		{
			goThroughParams(args...);
			string+="\n";
		}
	}
	template<typename T, typename ... PArgs>
	constexpr T goThroughParams(T first, PArgs ... args)
	{
		int number = static_cast<int>(first);
		if(number>9)string+="   ";
		else printLine(number,lH);
		goThroughParams(args...);
		return first;
	}
	template<typename T>
	constexpr T goThroughParams(T first) {
		int number = static_cast<int>(first);
		if(number>9)string+="   ";
		else printLine(number,lH);
		return first;
	}

	constexpr void printLine(int number, int lineHeight)
	{
		if(lineHeight%5==0)
		{
			switch(number)
			{
				case 1: 
					string+="   ";
				break;
				default: 
					string+=" \u2501 ";
				break;
			}
		}
		if(lineHeight%5==1)
		{
			switch(number)
			{
				case 0:
				case 4:
				case 8:
				case 9:
					string+="\u2503 \u2503";
				break;
				case 1:
				case 2:
				case 3:
				case 7:
					string+="  \u2503";
				break;
				default:
					string+="\u2503  ";
			}
		}
		if(lineHeight%5==2)
		{
			switch(number)
			{
				case 0:
				case 1:
				case 7: 
					string+="   ";
				break;
				default: 
					string+=" \u2501 ";
				break;
			}
		}
		if(lineHeight%5==3)
		{
			switch(number)
			{
				case 0:
				case 6:
				case 8:
					string+="\u2503 \u2503";
				break;
				case 2:
					string+="\u2503  ";
				break;
				default:
					string+="  \u2503";
			}
		}
		if(lineHeight%5==4)
		{
			switch(number)
			{
				case 1:
				case 4:
				case 7:
					string+="   ";
				break;
				default: 
					string+=" \u2501 ";
				break;
			}
		}
		string +=" ";
		
	}
	


	 operator const char *()  const
	{
		return static_cast<const char *>(string);
	}

private:
	PreAllocString<sizeof ...(Args) *40>string;
	int nrArgs =0;
	int lH=0;
};