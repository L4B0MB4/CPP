#include "PoolAllocator.h"
#include <stdio.h>
#include <new>

class Foo{
    public:
        int test=12;
        int test2 =13;
};

int main(int argc, char** args)
{
    printf("%d %s\n",argc,args[argc]);

    CREATE(p,2,8);
    Foo* foo = new(p.Allocate(sizeof(Foo))) Foo;
    Foo* ff = new(p.Allocate(sizeof(Foo))) Foo;
    ff->test = ff->test +20;
    printf("%d \n",ff->test);
    printf("%d \n",foo->test);
    printf("%d \n",p.Available());
    p.Deallocate(ff);
    Foo* fff = new(p.Allocate(sizeof(Foo))) Foo;
    fff->test = fff->test +60;
    printf("%d \n",fff->test);
    printf("%d \n",ff->test);

}
