#include "../include/Printf.h"
#include <stdio.h>

int main(int argp, char** args)
{
    printf("%d \n",argp);
    printf("%s\n",args[0]);
    int maxlen =100;
    char buffer[maxlen];
    char name[] = "Lars";
    int age=21, b =55;

    Printf(buffer,&maxlen,"Hallo ich bin %s und bin %d! tada",name, age, b);
    printf("BUFFER: %s",buffer);
    return 0;
}