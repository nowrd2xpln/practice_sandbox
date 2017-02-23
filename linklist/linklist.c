#include <stdio.h>

typedef struct node Node;
typedef struct list List;

struct
{
    int cnt;
    Node *next;
} node;

struct
{
    int num;
    Node *head;
    Node *tail
} list;

int main(void)
{
    printf("Link List Review\n");

    return 0;
}