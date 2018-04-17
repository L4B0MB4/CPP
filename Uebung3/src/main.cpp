#include <stdio.h>
#include "../include/PreAllocString.h"
#include <iostream>

int main(int argp, char** args)
{
    printf("%d \n",argp);
    printf("%s\n",args[0]);
    int len =100;
    char buffer[len];
    buffer[0] ='H';
    buffer[1] ='A';
    buffer[2] ='L';
    buffer[3] ='L';
    buffer[4] ='O';
    buffer[5] =0;
    PreAllocString p(buffer, buffer+len-1);

    p="was geht";
    printf("%d\n",p.GetLength());
    printf("%d\n",p.SizeOf());
    char a ='y';
    p = &a;
    printf("%d\n",p.GetLength());
    printf("%d\n",p.SizeOf());
    const char* x= "tadaaaaaaaaaaaaaaaaaaa";
    p=x;
    printf("%d\n",p.GetLength());
    printf("%d\n",p.SizeOf());
    printf("%s \n",static_cast<const char*>(p));
    printf("%s \n",static_cast<const void*>(p));
    p+=a;
    printf("%s \n",static_cast<const char*>(p));
    char bada[5] ="test";
    p+=bada;
    printf("%s \n",static_cast<const char*>(p));
    return 0;
}