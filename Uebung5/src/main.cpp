#include "PoolAllocator.h"
#include <stdio.h>

class Test{
    public:
        int test=12;
        int test2 =13;
};

int main(int argc, char** args)
{
    printf("%d %s\n",argc,args[argc]);

    CREATE(p,10,20);
    Test t = *reinterpret_cast<Test*>(p.Allocate(sizeof(Test)));
    printf("%d \n",t.test);

}
