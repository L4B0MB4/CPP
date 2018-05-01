#include <cstddef>
#include <stdio.h>
#include "IHeap.h"
template<size_t blockCount, size_t blockSize>
class PoolAllocator: public IHeap
{
    public:

        void* Allocate(size_t sizeInBytes)
        {
            printf("%d \n",sizeInBytes);
            return nullptr;
        }

        void Deallocate(void* p)
        {
            printf("p %d \n",p);
        }
        size_t Available() const
        {
            return 1;
        }
    private:
        char buffer[blockCount*blockSize];
        size_t size = blockCount*blockSize;
};

#define CREATE(varName, blockCount, blockSize) PoolAllocator<blockCount,blockSize> varName; 