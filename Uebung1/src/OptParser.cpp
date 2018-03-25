#include "../include/OptParser.h"
#include <string.h>

bool CmdLineOptParser::Parse(int argc, char* argv[] )
{
    argc--;
    bool wasAntotherArg =false;
    for(int i = 1; i<=argc;i++)
    {
        if(argv[i] == nullptr)return false;
        if(strlen(argv[i]) <=1)return false;
        if(argv[i][0]=='-')
        {
            if(strlen(argv[i])==2)
            {   
                if(i<argc)
                {
                    int j = i+1;
                    bool isValue = false;
                    if(argv[j][0]!='-')isValue=true;

                    if(isValue)
                    {
                        char* info = argv[j];
                        Option(argv[i][1],info);
                        i++;
                    }
                    else{
                        Option(argv[i][1],argv[i]+2);
                    }
                }
                else Option(argv[i][1],argv[i]+2);
            }
            else if(strlen(argv[i])>2)
            {
                char* info = argv[i] +2;
                if(info[0] == '=')info++;
                Option(argv[i][1],info);
            }
        }
        else return false;

       
        if(wasAntotherArg==true)i++;
        wasAntotherArg=false;
    }


    return true;
}

bool CmdLineOptParser::Option(const char c, const char* info)
{
    if(info[0]==0 && c >0)return true;
    return false;
}