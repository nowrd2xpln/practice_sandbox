#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

uint32_t test01();
uint32_t test02();
uint32_t test03();

int *two_sum(int *nums, int size, int tgt);

int main(void)
{
    int ret = 0;
    
    
    test01();

    return ret;
}

int *two_sum(int *nums, int size, int tgt)
{
    int *idxs = NULL;
    
    for(int i = 0; i < size; i++)
    {
        for( int j = i + 1; j < size; j++)
        {
            printf("%d ", j); 
            
    
        }
        printf("\n");
    }
    
    return idxs;
}

#define SIZE    4

uint32_t test01()
{
    uint32_t ret = 0;
    int nums[SIZE] = {2, 7, 11, 15};
    int tgt = 9;

    two_sum(nums, SIZE, tgt);
    
    return ret;
}
