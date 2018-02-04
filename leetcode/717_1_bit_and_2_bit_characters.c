#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

bool test01();
bool test02();
bool test03();
bool test04();
bool test05();

int main(void)
{
    int ret = 0;
    
    
    test01();
    test02();
    test03();
    test04();
    test05();

    return ret;
}


bool isOneBitCharacter(int* bits, int bitsSize)
{
    bool ret = false;
    int idx = 0;
 
    for(idx = 0; idx < bitsSize; ++idx)
    {
        //printf("idx %d\n", idx);

        switch(bits[idx])
        {
            case 1:
                ++idx;
                //printf("2bit\n");
                ret = false;
                break;
            case 0:
                //printf("1bit\n");
                ret = true;
                break;
            default:
                printf("invalid input %d\n", bits[idx]);
        }
    }
    
    return ret;
}

bool test01()
{
    bool ret = false;
    int array[] = {1,1,1,0,1,0,1,0,1,0,0};
    int len = sizeof(array)/sizeof(array[0]);

    printf("len %d\n", len);
    
    ret = isOneBitCharacter(array, len);

    printf("%d\n", ret?1:0);
    return ret;
}

bool test02()
{
    bool ret = false;
    int array[] = {0};
    int len = sizeof(array)/sizeof(array[0]);

    printf("len %d\n", len);
    
    ret = isOneBitCharacter(array, len);

    printf("%d\n", ret?1:0);
    return ret;
}

bool test03()
{
    bool ret = false;
    int array[] = {1,0};
    int len = sizeof(array)/sizeof(array[0]);

    printf("len %d\n", len);
    
    ret = isOneBitCharacter(array, len);

    printf("%d\n", ret?1:0);
    return ret;
}


bool test04()
{
    bool ret = false;
    int array[] = {1,0,1,1,1,1,1,0};
    int len = sizeof(array)/sizeof(array[0]);

    printf("len %d\n", len);
    
    ret = isOneBitCharacter(array, len);

    printf("%d\n", ret?1:0);
    return ret;
}


bool test05()
{
    bool ret = false;
    int array[] = {0,1,0};
    int len = sizeof(array)/sizeof(array[0]);

    printf("len %d\n", len);
    
    ret = isOneBitCharacter(array, len);

    printf("%d\n", ret?1:0);
    return ret;
}
