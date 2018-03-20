#include <stdio.h>
#include "../include/OptParser.h"

using namespace std;

int main(int argp, char** args)
{
    CmdLineOptParser parser;
    parser.Parse(argp,args);
    return 0;
}