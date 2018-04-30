#include <iostream>
#include "PreAllocString.h"
#include <stdarg.h>
#define MAX_DIGITS 10

template <typename ... Args>
class MultiDigit {

public:
	MultiDigit(Args ... args)
	{
		goThroughParams(args...);
		nrArgs = sizeof ...(args);
		printf("number of arguments %d\n",nrArgs);
		string="";
		for(lH=0;lH<5;lH++)
		{
			goThroughParams(args...);
			string+="\n";
		}
	}
	template<typename T, typename ... PArgs>
	T goThroughParams(T first, PArgs ... args)
	{
		const int number = static_cast<int>(first);
		if(number>9)string+="   ";
		else printLine(number,lH);
		goThroughParams(args...);
		return first;
	}
	template<typename T>
	T goThroughParams(T first) {
		const int number = static_cast<int>(first);
		if(number>9)string+="   ";
		else printLine(number,lH);
		return first;
	}

	void printLine(int number, int lineHeight)
	{
		if(lineHeight%5==0)
		{
			switch(number)
			{
				case 1: 
					string+="   ";
				break;
				default: 
					string+="\033[4m _ \033[0m";
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
					string+="\033[4m _ \033[0m";
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
					string+="| |";
				break;
				case 2:
					string+="|  ";
				break;
				default:
					string+="  |";
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
					string+=" \u203E ";
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
	PreAllocString<1000>string;
	int nrArgs =0;
	int lH=0;
};