#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

uint32_t test01();
uint32_t test02();
uint32_t test03();
uint32_t testx(char *argv);

int main(int argc, char *argv[])
{
    int ret = 0;
    
    printf("%d %s\n", argc, argv[1]);
    
    test01();
    test02();
    testx(argv[1]);

    return ret;
}

char* longestPalindrome(char* s)
{
    int length = 0;
    int l_most, r_most, big_sub_str_cnt;

    // Count length;
    length = strlen(s);
    printf("%s\n", s);
    printf("length: %d\n", length);

    // Check length > 2
    if(length < 2)
        return NULL;

    l_most = 0;
    r_most = 0;
    big_sub_str_cnt = 0;

    for(int i = 0; i < length; ++i)
    {
        int left = i;
        int right = i;
        int sub_str_cnt = 1;

        printf("%d - left: %02d\tright:%02d\n", i, left, right);

        // Skip same character
        while(s[right+1] == s[left])
        {
            right++;
            i++;
            r_most = right;
            sub_str_cnt++;
            printf("\tDuplicate found at position [%02d]\n", right);
            printf("\tleft: %02d\tright: %02d\n", left, right);
        }

        // Expand
        while(left - 1 >= 0 && right < (length-1) \
              && \
              s[right+1] == s[left -1])
        {
            
            --left;
            ++right;
            printf("\texpand l:%d r:%d\n", left, right);
            
            sub_str_cnt += 2;
        }
        
        if(big_sub_str_cnt < sub_str_cnt)
        {
            big_sub_str_cnt = sub_str_cnt;
            l_most = left;
            r_most = right;
        }

        printf("\tl_most:%d r_most:%d\n", l_most, r_most);
        printf("\tsub_str_cnt:%d\n", sub_str_cnt);
    }
    printf("l_most:%d r_most:%d\n", l_most, r_most);
    printf("big_sub_str_cnt:%d\n", big_sub_str_cnt);

    while(l_most <= r_most)
    {
        printf("%c", s[l_most++]);
    }
    printf("\n\n");

    return s;
}
uint32_t test01()
{
    uint32_t ret = 0;
    char *pal;
    char word[] = "babad";

    pal = longestPalindrome(word);
    return ret;
}

uint32_t test02()
{
    uint32_t ret = 0;
    char *pal;
    char word[] = "cbbd";

    pal = longestPalindrome(word);
    return ret;
}

uint32_t testx(char *s)
{
    uint32_t ret = 0;
    char *pal;
    char *word = s;

    pal = longestPalindrome(word);
    return ret;
}