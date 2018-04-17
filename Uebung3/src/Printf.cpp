#include "../include/Printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <iostream>


char* Printf(char* dst, const void* end, const char* fmt,va_list vl)
{
    if(dst==nullptr || end==nullptr || fmt==nullptr ||dst==NULL || end==NULL|| fmt==NULL)return nullptr;
    const char* iPEnd =reinterpret_cast<const char*>(end);
    const char* iPDest =reinterpret_cast<const char*>(dst);
    // clear buffer
    int iEnd = iPEnd-iPDest;
    // clear buffer
    for(int i =0; i<(iEnd);i++)
    {
        dst[i]=0;
    }
    //get length of string
    int length =std::char_traits<char>::length(fmt);
    //setup variable arg-list
    char*  val;
    //buffer for arguments
    int bufferlength =iEnd;
    char buffer[bufferlength];
    //offset for dest and fmt. Needed for replacement of %X 
    int offset=0;
    int coffset=0;
    int i;
    for( i=0; i<length && (i+offset+1)<(iEnd);++i){
        //write each char of fmt into dst
        dst[i+offset] = fmt[i+coffset];
        if(fmt[i+coffset]==0) //if fmt has 0-terminator ->break
        {
            break;
        }
        if(i+1+coffset<length) // if not last char
        {
            if(fmt[i+coffset] == '%' && fmt[i+1+coffset] != '%') // is %X and not %%
            {
                val = va_arg(vl,char *); // read next argument
                getString(fmt[i+1+coffset],val,buffer,bufferlength); // buffer gets filled out with argument value (formatted)
                for(int j=0;j<bufferlength;j++)
                {
                    if(buffer[j]==0) // 0-terminator ? ->break
                    {
                        buffer[j]=0;
                        offset+=j-1;
                        coffset+=1;
                        break;
                    }
                    else if(j<bufferlength)// write into dest 
                    {
                        dst[j+i+offset]=buffer[j];
                        buffer[j]=0;
                    }
                }
            }
            else if(fmt[i+coffset] == '%' && fmt[i+1+coffset] == '%'){ // replace %% with %
                i+=1;
                offset--;
            }
        }
    }
    return &(dst[i+offset]); // return next writeable char
}

void getString(char type, void* param, char* buffer, const int buffermaxlen)
{
    if(param==nullptr || param == NULL)return;
    switch(type)
    {
        case 'c': snprintf(buffer,buffermaxlen,"%c",param);break; // using snprintf to convert argument value into formatted value
        case 'd': snprintf(buffer,buffermaxlen,"%d",param);break;
        case 'x': snprintf(buffer,buffermaxlen,"0x%x",param);break;
        case 's': 
        {
                snprintf(buffer,buffermaxlen,"%s",param);break;
        }
        case 'b': decimalToBinary(param,buffer, buffermaxlen); break; // own impl
        case 'u':snprintf(buffer,buffermaxlen,"%u",param);break;
    }
}

void decimalToBinary(void* param, char* buffer, const int buffermaxlen)
{
    int  n =  *reinterpret_cast<int*>(&param); // why is adress of param needed to cast?
    buffer[0]='0';
    buffer[1]='b';
    int i=0;
    int umkehren=0;
    if(n>=0) // if positiv shift int right and write from left to right
    {
        while (n && i-2 <buffermaxlen) {
        if (n & 1)
            buffer[i+2]='1';
        else
            buffer[i+2]='0';
        ++i;
        n >>= 1;
        }
    buffer[i+1]=0;
    }
    else if(n<0 &&i <buffermaxlen) // if negtive shift int right and write from right to left
    {
        umkehren= 64;//64 bit number
        umkehren +=2; // +2 -> not overwrite "0b"
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
}