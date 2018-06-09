/*
*   7. Reverse Integer
*
*   Given a 32-bit signed integer, reverse digits of an integer.
*/

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int reverseInteger(int num);

uint32_t test01();
uint32_t test02();
uint32_t test03();

int main(void)
{
    int ret = 0;
    
    test01();

    return ret;
}

int reverseInteger(int num)
{
    int remainder = 0;
    int reverse = 0;
    int tmp = num;

    while(tmp > 0)
    {
        remainder = tmp % 10;
        tmp /= 10; 
        
        reverse = reverse * 10 + remainder;

        printf("%d\n", reverse);
    }

    return 0;
}

uint32_t test01()
{
    uint32_t ret = 0;

    reverseInteger(4321);
    
    return ret;
}
