#include <stdio.h>

// To execute C, please define "int main()"

/**
 * Given a string, print out how many of each letter appear in the string.
 * Letters only.
 *
 * "Hhello" --> "h:2, e:1, l:2, o:1"
 */
void histogram(char * s);

int main() {
  char input[] = "Hhello";
  
  histogram(input);
  
  return 0;
}


void histogram(char * s)
{
  char freq[26] = {0};
  char letter = 'a';
  unsigned int i = 0;
  
  printf("input = %s\n", s);
  
  while(*s)
  {
    //-- change to uppercase if lowercase
    if(*s > 'Z')
    {
      *s -= 32;
    }
    
    printf(" %c\n", *s);
    
    // Translate letter to lower range 0-25
//    *s -= 65;
    
    printf(" %d\n", *s);
    switch(*s)
    {
      case 'A':
        freq[0]++;
        break;
      case 'B':
        freq[1]++;
        break;
      case 'E':
        freq[2]++;
        break;
      case 'L':
        freq[3]++;
        break;
      case 'O':
        freq[4]++;
        break;
      case 'H':
        freq[5]++;
        break;
      default:
        break;
    }
    s++;
  }
  

  //
  for(i = 0; i < 26; ++i, ++letter)
  {
    printf("%c: %d\n", letter, freq[i]);   
  }
}
