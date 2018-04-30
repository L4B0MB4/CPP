#include <iostream>
#include "PreAllocString.h"
#include <stdarg.h>
#define BIGGEST_DIGIT 9
#define LINES 5

template <typename ... Args>
class MultiDigit {

public:
	constexpr MultiDigit(Args ... args)
	{
		string.Empty();
		for(lH=0;lH<LINES;lH++)
		{
			goThroughParams(args...);
			string+="\n";
		}
	}
	template<typename T, typename ... PArgs>
	constexpr T goThroughParams(T first, PArgs ... args)
	{
		int number = static_cast<int>(first);
		if(number>BIGGEST_DIGIT)string+="   ";
		else printLine(number,lH);
		goThroughParams(args...);
		return first;
	}
	template<typename T>
	constexpr T goThroughParams(T first) {
		int number = static_cast<int>(first);
		if(number>BIGGEST_DIGIT)string+="   ";
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
					string+=" - ";
				break;
			}
		}
		else if(lineHeight%5==1)
		{
			switch(number)
			{
				case 0:
				case 4:
				case 8:
				case 9:
					string+="| |";
				break;
				case 1:
				case 2:
				case 3:
				case 7:
					string+="  |";
				break;
				default:
					string+="|  ";
			}
		}
		else if(lineHeight%5==2)
		{
			switch(number)
			{
				case 0:
				case 1:
				case 7: 
					string+="   ";
				break;
				default: 
					string+=" - ";
				break;
			}
		}
		else if(lineHeight%5==3)
		{
			switch(number)
			{
				case 0:
				case 6:
				case 8:
					string+="| |";
				break;
				case 2:
					string+="|  ";
				break;
				default:
					string+="  |";
			}
		}
		else if(lineHeight%5==4)
		{
			switch(number)
			{
				case 1:
				case 4:
				case 7:
					string+="   ";
				break;
				default: 
					string+=" - ";
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
	PreAllocString<sizeof ...(Args) *21>string;
	int lH=0;
};