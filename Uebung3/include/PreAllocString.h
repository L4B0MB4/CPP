#include <stdio.h>
typedef long unsigned int size_t;

class PreAllocString{

    size_t maxlLen;
    size_t currentLen;
    char* buffer;

    public:

        PreAllocString(char* s, char* end){
            buffer = s;
            maxlLen = end-s;
            currentLen=0;
        }
        ~PreAllocString(){
            printf("destroying %s\n",buffer);
        }
        operator const char*() const;
        operator const void*() const;
        const char & operator [] (const int idx);
        size_t GetLength() const;
        constexpr size_t SizeOf()
        {
            printf("max len \n");
            return maxlLen;
        }
        void Empty();
        PreAllocString& operator =(char rhs);
        PreAllocString& operator =(const char* rhs);
        PreAllocString& operator =(char *const rhs);

        PreAllocString& operator +=(char rhs);
        PreAllocString& operator +=(char *const rhs);

        void AddFormat(const char* format,...);
        void AddWhiteSpace();
};

#define CREATE(varName,size) \
    char buffer_varName[size];\
    PreAllocString varName(buffer_varName,buffer_varName+size-1) 
    