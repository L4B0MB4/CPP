#include "../include/Printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <iostream>


char* Printf(char* dst, const void* end, const char* fmt,...)
{
    const int* iEnd =reinterpret_cast<const int*>(end);
    for(int i =0; i<(*iEnd);i++)
    {
        dst[i]=0;
    }
    const char* cFmt =reinterpret_cast<const char*>(fmt);
    int length =std::char_traits<char>::length(cFmt);
    char*  val;
    va_list vl;
    va_start(vl,fmt);
    int bufferlength =*iEnd;
    char buffer[bufferlength];
    int offset=0;
    int coffset=0;
    int i;
    for( i=0; i<length && (i+offset)<(*iEnd);++i){
        dst[i+offset] = cFmt[i+coffset];
        if(cFmt[i+coffset]==0)
        {
            break;
        }
        if(i+1+coffset<length)
        {
            if(cFmt[i+coffset] == '%' && cFmt[i+1+coffset] != '%')
            {
                val = va_arg(vl,char *);
                getString(cFmt[i+1+coffset],val,buffer);
                for(int j=0;j<bufferlength;j++)
                {
                    if(buffer[j]==0)
                    {
                        buffer[j]=0;
                        offset+=j-1;
                        coffset+=1;
                        break;
                    }
                    else if(j<bufferlength)
                    {
                        dst[j+i+offset]=buffer[j];
                        buffer[j]=0;
                    }
                }
            }
            else if(cFmt[i+coffset] == '%' && cFmt[i+1+coffset] == '%'){
                i+=1;
                offset--;
            }
        }
    }
    return &(dst[i+offset]);
}

void getString(char type, void* param, char* buffer)
{
    switch(type)
    {
        case 'd': sprintf(buffer,"%d",param);break;;
        case 'u': sprintf(buffer,"%u",param);break;
        case 'x': sprintf(buffer,"0x%x",param);break;
        case 's': sprintf(buffer,"%s",param);break;
        case 'b': 
        printf("hier");
       int  n =  *reinterpret_cast<int*>(&param); // wieso brauch ich erst die adresse von param?
        printf("%d",n);
        buffer[0]='0';
        buffer[1]='b';
        int i=0;
        int umkehren=0;
        if(n>=0)
        {
            while (n) {
            if (n & 1)
                buffer[i+2]='1';
            else
                buffer[i+2]='0';
            ++i;
            n >>= 1;
            }
        buffer[i+1]=0;
        }
        else if(n<0) // alles rückwärts
        {
            umkehren= 64;//64 bit zahlen
            umkehren +=2;
            while (n&& i <= umkehren-2) {
                if (n & 1)
                    buffer[umkehren-i]='1';
                else
                    buffer[umkehren-i]='0';
                ++i;
                n >>= 1;
            }
            buffer[umkehren+1]=0;
        }
        break;
    }
}