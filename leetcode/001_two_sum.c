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
    int *ans = NULL;

    ans = (int *) malloc(2*sizeof(int));
    // error check 

    for(int i = 0; i < size; i++)
    {
        for( int j = i + 1; j < size; j++)
        {
            //printf("%d ", j); 
            printf("%d = %d - %d\n", nums[j], tgt, nums[i]);
            if( nums[j] == tgt - nums[i] )
            {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
        printf("\n");
    }
    
    printf("ERROR: No sum detected!\n");
    return NULL;
}

#define SIZE    4

uint32_t test01()
{
    uint32_t ret = 0;
    int nums[SIZE] = {2, 7, 11, 15};
    int tgt = 26;
    int *ans = NULL;

    ans = two_sum(nums, SIZE, tgt);
    if(ans)
    {
        printf("Answer: %d %d\n", ans[0], ans[1]);
    }
    else
    {
        exit(-1);
    }

    return ret;
}
