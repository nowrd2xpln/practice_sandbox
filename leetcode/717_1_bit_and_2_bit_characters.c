#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

uint32_t test01();
uint32_t test02();
uint32_t test03();

int main(void)
{
    int ret = 0;
    
    
    test01();

    return ret;
}

uint32_t test01()
{
    uint32_t ret = 0;
    int array[] = {1,1,1,0};
    int size = sizeof(array)/sizeof(array[0]);
    int len = sizeof(array)/sizeof(int);
    int idx = 0;

    printf("size %d\n", size);
    printf("len %d\n", len);

    
    return ret;
}
