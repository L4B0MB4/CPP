#include "../include/PreAllocString.h"


    PreAllocString::operator const char*() const{
        printf("char cast\n");
        return buffer;
    }

    PreAllocString::operator const void*() const{
        printf("void cast\n");
        return reinterpret_cast<void *>(buffer);
    }

    size_t PreAllocString::GetLength() const
    {
        printf("curr len \n");
        return currentLen;
    }


    const char & PreAllocString::operator [] (const int idx)
    {
        printf("char at\n");
        unsigned int id  = static_cast<unsigned int>(idx);
        if(id<=maxlLen)
        {
            return buffer[id];
        }
        return buffer[maxlLen];
    }
    
    PreAllocString& PreAllocString::operator =(char rhs)
    {
        printf("is char \n");
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
        printf("is string \n");
        unsigned int i=0;
        for(i=0;i<maxlLen;i++)
        {
            buffer[i]=rhs[i];
            if(rhs[i]==0)break; 
        }
        currentLen=i;
        return (*this);
    }

    PreAllocString& PreAllocString::operator =(char *const rhs)
    {
        printf(" is char pointer \n");
        if(maxlLen>0)
        {
            buffer[0]=*rhs;
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

    PreAllocString& PreAllocString::operator +=(char rhs)
    {
        printf("+= char %c",rhs);
        if(currentLen+1<maxlLen)
        {
            buffer[currentLen]=rhs;
            buffer[currentLen+1]=0;
        }
        ++currentLen;
        return (*this);
    }

    PreAllocString& PreAllocString::operator +=(char *const rhs)
    {
        printf("+= string %s",rhs);
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
        for(unsigned int i=0;i<maxlLen;i++)
        {
            buffer[i]=0;
        }
        currentLen=0;
    }

        void PreAllocString::AddFormat(const char* format,...)
        {
            printf("Formatting...\n %s",format);
        }
        void PreAllocString::AddWhiteSpace()
        {
            printf("Adding Whitespace...\n");
            if(currentLen+1<maxlLen)
            {
                buffer[currentLen]=' ';
                buffer[currentLen+1]=0;
                currentLen++;
            }
        }

