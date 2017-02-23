#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct list List;

struct
{
    int data;
    Node *next;
} node;

struct
{
    int cnt;
    Node *head;
    Node *tail;
} list;

List *initList(void)
{
    List *llist = NULL;

    llist = (List *) malloc(sizeof(list));

    return llist;
}

int deleteList(List *llist)
{
    free(llist);

    return 0;
}

int insertNode(List *llist, int value)
{
    Node *newnode = NULL;
    int ret = 0;

    // Create new node
    newnode = (Node *) malloc(sizeof(node));

    if(newnode == NULL)
    {
        printf("Failed to allocate memory for new node\n");
        ret = -1;
    }
    else
    {
        newnode->data = 0;
    }

    return ret;
}

void traverseList(List *llist)
{
    return 0;
}

int main(void)
{
    printf("Link List Review\n");

    return 0;
}