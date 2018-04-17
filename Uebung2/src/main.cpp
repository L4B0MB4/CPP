#include "../include/Printf.h"
#include <stdio.h>

int main(int argp, char** args)
{
    printf("%d \n",argp);
    printf("%s\n\n\n",args[0]);
    int maxlen =200;
    char buffer[maxlen];
    //char e[] = "Lars";
    int a=21;// b =-700, c=0xf, d=0b111;
    char f='b';

    char* x = Printf(buffer,buffer+maxlen-1,"Hallo %d hallo %u hallo %c hallo %s hallo %x hallo %b hallo %% hallo",a,a,a,a,a,a);
    printf("%s \n",buffer);
    printf("%c \n",*x);
    /*x = Printf(buffer,buffer+maxlen-1,"Hallo %d hallo %u hallo %c hallo %s hallo %x hallo %b hallo %% hallo",b,b,b,b,b,b);
    printf("%s \n",buffer);
    printf("%c \n",*x);
    x = Printf(buffer,buffer+maxlen-1,"Hallo %d hallo %u hallo %c hallo %s hallo %x hallo %b hallo %% hallo",c,c,c,c,c,c);
    printf("%s \n",buffer);
    printf("%c \n",*x);
    x = Printf(buffer,buffer+maxlen-1,"Hallo %d hallo %u hallo %c hallo %s hallo %x hallo %b hallo %% hallo",d,d,d,d,d,d);
    printf("%s \n",buffer);
    printf("%c \n",*x);
    x = Printf(buffer,buffer+maxlen-1,"Hallo %d hallo %u hallo %c hallo %s hallo %x hallo %b hallo %% hallo",e,e,e,e,e,e);
    printf("%s \n",buffer);
    printf("%c \n",*x);
    x = Printf(buffer,buffer+maxlen-1,"Hallo %d hallo %u hallo %c hallo %s hallo %x hallo %b hallo %% hallo",f,f,f,f,f,f);
    printf("%s \n",buffer);
    printf("%c \n",*x);*/
    x = Printf(nullptr,buffer+maxlen-1,"Hallo %d hallo %u hallo %c hallo %s hallo %x hallo %b hallo %% hallo",f,f,f,f,f,f);
    printf("daaa\n");
    x = Printf(nullptr,buffer+maxlen-1,"Hallo %d hallo %u hallo %c hallo %s hallo %x hallo %b hallo %% hallo",f,f,f,f,f,f);
    printf("daaa\n");
    x = Printf(buffer,nullptr,"Hallo %d hallo %u hallo %c hallo %s hallo %x hallo %b hallo %% hallo",f,f,f,f,f,f);
    printf("daaa\n");
    x = Printf(buffer,buffer+maxlen-1,NULL,f,NULL,f,f,f);
    printf("daaa\n");
    return 0;
}