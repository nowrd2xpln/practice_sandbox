#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

uint32_t test01();
uint32_t test02();
uint32_t test03();

int numberOfSteps(int num) {
    unsigned int cnt;
    unsigned int x;

    // Validate number
    if(num < 0) return -1;
    if(num == 0) return 0;

    for(cnt = 0; num > 0; cnt++) {
        // Check even or odd
        if(num & 1) {
            num--;
        }
        else {
            num >>= 1;
        }
    }
    return cnt;
}

int main(void)
{
    int ret = 0;
    
    
    test01();

    return ret;
}

uint32_t test01()
{
    uint32_t ret = 0;
    int x;
    
    for(x = 10; x >= 0; x--) {
        printf("%3d: %d\n", x, numberOfSteps(x));
    }
    return ret;
}
