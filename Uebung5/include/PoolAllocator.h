#include <cstddef>
#include <stdio.h>
#include "IHeap.h"
template<size_t blockCount, size_t blockSize>
class PoolAllocator: public IHeap
{
    public:

        PoolAllocator():
            buffer{},
            free{}
        {
            for(size_t i=0;i<blockCount;i++)
            {
                free[i]=1;
            }
        }

        void* Allocate(size_t sizeInBytes)
        {
            printf("%d \n",sizeInBytes);
            if(sizeInBytes>Available())
            {
                return nullptr;
            }
            else
            {
                size_t i=0;
                for(;i<blockCount;i++)
                {
                    if(free[i]==1)
                    {
                        free[i]=0;
                        break;
                    }
                }
                return buffer+i*blockSize;
            }
        }

        void Deallocate(void* p)
        {
            char* pp = reinterpret_cast<char*>(p);
            printf("pointer %d\n",pp-buffer);
            free[(pp-buffer)/blockSize]=1;
        }
        size_t Available() const
        {
            size_t av=0;
            for(size_t i=0;i<blockCount;i++)
            {
                if(free[i]==1)
                {
                    ++av;
                }
            }
            return av*blockSize;
        }
    private:
        char buffer[blockCount*blockSize];
        size_t maxSize = blockCount*blockSize;
        char free[blockCount];
};

#define CREATE(varName, blockCount, blockSize) PoolAllocator<blockCount,blockSize> varName; 