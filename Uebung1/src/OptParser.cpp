#include "../include/OptParser.h"
#include <stdio.h>
#include <string.h>

bool CmdLineOptParser::Parse(int argc, char* argv[] )
{
    argc--;
    printf("Anzahl Args: %d \n",argc);

    for(int i = 1; i<=argc;i++)
    {
        if(argv[i] == nullptr)return false;
        if(strlen(argv[i]) <=1)return false;
        char* info = argv[i] +2;
        Option(argv[i][1],info);
    }


    return false;
}

bool CmdLineOptParser::Option(const char c, const char* info)
{
    printf("Char: %c\n",c);
    printf("Chars: %s\n",info);
    printf(" bool %d",info[0] ==0);
    return true;
}