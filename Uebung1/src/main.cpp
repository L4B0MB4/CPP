#include "../include/OptParser.h"

int main(int argp, char** args)
{
    CmdLineOptParser parser;
    parser.Parse(argp,args);
    return 0;
}