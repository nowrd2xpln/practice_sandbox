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

int numJewelsInStones(char* J, char* S)
{
    int ret = 0;
    char *p = S;
    int hash[52] = {0};
 
    while( *p )
    {
        switch(*p)
        {
            case 'a':
                hash['a'-'a']++;
                break;
            case 'b':
                hash['b'-'a']++;
                break;
            case 'c':
                hash['c'-'a']++;
                break;
            case 'd':
                hash['d'-'a']++;
                break;
            case 'e':
                hash['e'-'a']++;
                break;
            default:
                printf("Invalid input %c\n", *p);
        }
        p++;
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
