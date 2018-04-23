#include <stdio.h>
typedef long unsigned int size_t;

class PreAllocString{

    size_t maxlLen =0;
    size_t currentLen =0;
    char* buffer;

    public:

        PreAllocString(char* s, char* end){ // set variables
        if(s==nullptr || end == nullptr)return;
            buffer = s;
            maxlLen = end-s;
            currentLen=0;
        }
        ~PreAllocString() =default;
        operator const char*() const;
        operator const void*() const;
        const char & operator [] (const int idx);
        size_t GetLength() const;
        constexpr size_t SizeOf()
        {
            //printf("max len \n");
            return maxlLen;
        }
        void Empty();
        PreAllocString& operator =(char rhs);
        PreAllocString& operator =(const char* rhs);
        PreAllocString& operator =(char *const rhs);

        PreAllocString& operator +=(char rhs);
        PreAllocString& operator +=(char const* rhs);

        void AddFormat(const char* format,...);
        void AddWhiteSpace();
};

#define CREATE(varName,size) \
    char buffer_##varName[size];\
    PreAllocString varName(buffer_##varName,buffer_##varName+size-1) 
    