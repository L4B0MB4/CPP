#include <stdio.h>
#include "../include/PreAllocString.h"
#include <iostream>

int main(int argp, char** args)
{
    printf("%d \n",argp);
    printf("%s\n",args[0]);
    int len =100;
    char buffer[len];
    PreAllocString p(buffer, buffer+len-1);
    
    p="was geht";
    p+="hallo";
    printf("%d\n",p.GetLength());
    char a ='y';
    p = &a;
    printf("daaa %d\n",p.GetLength());
    char x[30]= "tadaaaaaaaaaaaaaaaaaaa";
    p=x;
    p.Empty();
    printf("hiiier %d\n",p.GetLength());
    p="hallo maaaan";
    printf("%s \n",static_cast<const char*>(p));
    p.AddFormat("test %s test","haha");
    printf("%s void pointer \n",static_cast<const void*>(p));
    p+=a;
    p.AddWhiteSpace();
    printf("%s \n",static_cast<const char*>(p));
    char bada[5] ="test";
    p+=bada;
    printf("%s \n",static_cast<const char*>(p));

    p.AddFormat("tryyyy%sing\n","asasd");
    printf("%s \n",static_cast<const char*>(p));

    printf("\n");
    CREATE(name,100);
    char b[10] ="was geht";
    name+=b;
    printf("\n");
    CREATE(namex,100);
    namex+=b;
    namex="trololo";
    printf("%s\n",namex);
    return 0;
}