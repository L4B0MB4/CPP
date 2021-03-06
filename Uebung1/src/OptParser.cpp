#include "../include/OptParser.h"
#include <string.h>


bool CmdLineOptParser::Parse(int argc, char* argv[] )
{
    for(int i = 1; i<argc;i++) // start with 2nd argument. 1. is fileinfo
    {
        if(argv[i] == nullptr)return false; 
        if(strlen(argv[i]) <=1)return false;
        if(argv[i][0]=='-') // current param starts with "-" ? else -> error
        {
            if(strlen(argv[i])==2) // strlen ==2 -> bool or  value in 2 diffrent params
            {   
                if(i<argc-1) // any other params left ? -> maybe not ool
                {
                    int j = i+1;
                    bool isValue = false;
                    if(argv[j][0]!='-' && argv[j][0] !='\0')isValue=true;
                    if(isValue) // next param not starting with "-" -> value for current param
                    {
                        char* info = argv[j];
                        Option(argv[i][1],info);
                        ++i;
                    }
                    else{
                        Option(argv[i][1],argv[i]+2); //isbool
                    }
                }
                else Option(argv[i][1],argv[i]+2);//isbool --> stringterminator = info
            }
            else if(strlen(argv[i])>2) // everything else
            {
                char* info = argv[i] +2;
                if(info[0] == '=')info++;
                if(info[0]=='\0')return false; // z.B. falls -x=\0
                Option(argv[i][1],info);
            }
            else
            {
                return false;
            }
        }
        else return false;
    }
    return true;
}

bool CmdLineOptParser::Option(const char c, const char* info)
{
    if(info[0]=='\0' && c >0)return true;
    return false;
}