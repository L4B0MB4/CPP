#include "PreAllocString.h"
#include <stdio.h>


int main(int argc, char** args)
{
    printf("%d %s\n",argc,args[argc]);
    CREATE(test, 100);
    printf("niiice\n");
    printf("%d\n",test.GetLength());
    test="hallo";
    printf("nnnnice %s\n",static_cast<const char*>(test));
    test+=" wie gehts";
    printf("\ngawd %s \n",static_cast<const char*>(test));
}