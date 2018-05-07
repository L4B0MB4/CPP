#include <cstddef>
#include <stdio.h>
#include "IHeap.h"
template<size_t blockCount, size_t blockSize>
class PoolAllocator: public IHeap
{
    public:
        PoolAllocator():
            buffer{},
            used{}
        {
        }

        void* Allocate(size_t sizeInBytes)
        {
            if(sizeInBytes>Available())
            {
                return nullptr;
            }
            else
            {
                size_t i=0;
                for(;i<blockCount;i++)
                {
                    if(used[i]==0)
                    {
                        used[i]=1;
                        break;
                    }
                }
                return buffer+i*blockSize;
            }
        }

        void Deallocate(void* p)
        {
            if(p==nullptr)return;
            char* pp = reinterpret_cast<char*>(p);
            used[(pp-buffer)/blockSize]=0;
        }
        size_t Available() const
        {
            size_t av=0;
            for(size_t i=0;i<blockCount;i++)
            {
                if(used[i]==0)
                {
                    ++av;
                }
            }
            return av*blockSize;
        }
    private:
        char buffer[blockCount*blockSize];
        char used[blockCount];
};

#define CREATE(varName, blockCount, blockSize) PoolAllocator<blockCount,blockSize> varName; 