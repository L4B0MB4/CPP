#include "../include/Printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <iostream>


char* Printf(char* dst, const void* end, const char* fmt,...)
{
    printf("%s\n",end);
    const char* cEnd =reinterpret_cast<const char*>(fmt);
    int length =std::char_traits<char>::length(cEnd);
    void*  val;
    va_list vl;
    va_start(vl,fmt);
    int bufferlength =100;
    char buffer[bufferlength];
    int offset=0;
    int coffset=0;
    for(int i=0; i<length;++i){
        dst[i+offset] = cEnd[i+coffset];
        printf("dd %s \n",dst);
        if(i+1+coffset<length)
        {
            if(cEnd[i+coffset] == '%' && cEnd[i+1+coffset] != '%')
            {
                val = va_arg(vl,void *);
                getString(cEnd[i+1+coffset],val,buffer);
                printf("DEST %s \n",dst);
                printf("hier %s \n",buffer);
                for(int j=0;j<bufferlength;j++)
                {
                    if(buffer[j]==0)
                    {
                        buffer[j]=0;
                        offset=j-1;
                        coffset+=1;
                        printf("CEND %c \n",cEnd[i+coffset]);
                        printf("DEST %s \n",dst);
                        break;
                    }
                    else if(j<bufferlength)
                    {
                        dst[j+i+offset]=buffer[j];
                        buffer[j]=0;
                    }
                }
            }
            else if(cEnd[i+coffset] == '%' && cEnd[i+1+coffset] == '%'){
                i+=1;
                dst[i+offset]='%';
            }
        }
    }

    return NULL;
}

void getString(char type, void* param, char* buffer)
{
    switch(type)
    {
        case 'd': sprintf(buffer,"%d",param);break;;
        case 'u': sprintf(buffer,"%u",param);break;
        case 'x': sprintf(buffer,"%c",param);break;
        case 's': sprintf(buffer,"%s",param);break;
    }
}