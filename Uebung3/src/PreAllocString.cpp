#include "../include/PreAllocString.h"
#include "../include/Printf.h"
#include <stdarg.h>

    PreAllocString::operator const char*() const{
        return buffer;
    }

    PreAllocString::operator const void*() const{
        return reinterpret_cast<void *>(buffer);
    }

    size_t PreAllocString::GetLength() const
    {
        return currentLen;
    }


    const char & PreAllocString::operator [] (const int idx)
    {
        unsigned int id  = static_cast<unsigned int>(idx);
        if(id<=maxlLen)
        {
            return buffer[id];
        }
        return buffer[maxlLen];
    }
    
    PreAllocString& PreAllocString::operator =(char rhs)
    {
        if(maxlLen>0)
        {
            buffer[0]=rhs;
            unsigned int i =0;
            if(maxlLen>1)
            {
                for(i=1;i<maxlLen;i++)
                {
                    buffer[i]=0;
                }
            }
            currentLen=i;
        }
        return (*this);
    }

    PreAllocString& PreAllocString::operator =(const char* rhs)
    {
        //printf("is string %s \n",rhs);
        if(!rhs)return (*this);
        unsigned int i=0;
        for(i=0;i<maxlLen;i++)
        {
            buffer[i]=rhs[i];
            if(rhs[i]==0)break; 
        }
        currentLen=i;
        //printf("%s\n",buffer);
        return (*this);
    }

    PreAllocString& PreAllocString::operator =(char *const rhs)
    {
        if(maxlLen>0 && rhs)
        {
           unsigned int i=0;
            for(i=0;i<maxlLen;i++)
            {
                buffer[i]=rhs[i];
                if(rhs[i]==0)break; 
            }
            currentLen=i;
        }
        return (*this);
    }

    PreAllocString& PreAllocString::operator +=(char rhs)
    {
        //printf("+= char %c",rhs);
        if(currentLen+1<maxlLen)
        {
            buffer[currentLen]=rhs;
            buffer[currentLen+1]=0;
        }
        ++currentLen;
        return (*this);
    }

    PreAllocString& PreAllocString::operator +=(char const* rhs)
    {
        //printf("+= string %s",rhs);
        unsigned int i=0;
        for(i=0;i+currentLen<maxlLen;i++)
        {
            buffer[i+currentLen]=rhs[i];
            if(rhs[i]==0)break;
        }
        currentLen+=i;
        return (*this);
    }

    void PreAllocString::Empty()
    {
        if(maxlLen>0)
        {
            buffer[0]=0;
        }
        currentLen=0;
    }

    void PreAllocString::AddFormat(const char* format,...)
    {
        //printf("Formatting...\n%s",format);
        va_list args;
        va_start(args, format);
        char* x = Printf(buffer+currentLen,buffer+maxlLen,format,args);
        va_end(args);
        currentLen = x-buffer;
    }
    void PreAllocString::AddWhiteSpace()
    {
        //printf("Adding Whitespace...\n");
        if(currentLen+1<maxlLen)
        {
            buffer[currentLen]=' ';
            buffer[currentLen+1]=0;
            currentLen++;
        }
    }

