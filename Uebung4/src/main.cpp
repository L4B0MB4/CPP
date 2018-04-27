#include "PreAllocString.h"
#include "7Segment.h"
#include <stdio.h>

class Test{

public:
    Test(int t, int t2)
    {
        printf("t %d t2 %d\n",t,t2);
    }
};

int main(int argc, char** args)
{
    printf("%d %s\n",argc,args[argc]);
    /*CREATE(test, 100);
    printf("niiice\n");
    printf("%d\n",test.GetLength());
    test="hallo";
    printf("nnnnice %s\n",static_cast<const char*>(test));
    test+=" wie gehts";
    printf("\ngawd %s \n",static_cast<const char*>(test));
    //int sum = adder{1,2,3,4};*/
    //constexpr MultiDigit t {1,2,3,4,5,6,7,8,9,0,10,1,2,3,4,5,6,7,8,9,0,1};
    //printf("\n%s\n",static_cast<const char*>(t));
    MultiDigit tt {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8};
    printf("\n%s\n",static_cast<const char*>(tt));
    /*constexpr MultiDigit ttt {1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7};
    printf("\n%s\n",static_cast<const char*>(ttt));
    constexpr PreAllocString<100> string;
    string.GetLength();*/
}
