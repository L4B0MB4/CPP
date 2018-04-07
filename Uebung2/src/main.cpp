#include "../include/Printf.h"
#include <stdio.h>

int main(int argp, char** args)
{
    printf("%d \n",argp);
    printf("%s\n",args[0]);
    int maxlen =1000;
    char buffer[maxlen];
    char name[] = "Lars";
    int age=21, b =55,c=-700;

    char* x = Printf(buffer,&maxlen,"Hallo ich bin %s %% %% und bin %d! tada %x %b",name, age, b, c);
    printf("%s \n",buffer);
    printf("%c \n",*x);
    return 0;
}