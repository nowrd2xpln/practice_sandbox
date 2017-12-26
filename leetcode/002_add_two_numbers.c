#include <stdio.h>
#include <string.h>

/** @brief Takes a string and reverses the order of
 *         characters.
 *
 *  @param s The input string to be reversed
 *         row will be written.
 *
 *  @return void.
 */
void reverseString(char* s) {
    char *fwd = s;
    char *bwd = s + strlen(s) - 1;;
    
    for(;fwd < bwd; fwd++, bwd--) {
        // Swap
        *fwd ^= *bwd;
        *bwd ^= *fwd;
        *fwd ^= *bwd;
    }
}

int main(void)
{
  char input[] = "this is my string";
  
  printf("Before: %s\n", input);
  reverseString(input);
  printf("After : %s\n", input);
  
  return 0;
}