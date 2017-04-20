#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct list List;

typedef struct node
{
    int data;
    Node *next;
} Node;

typedef struct list
{
    int cnt;
    Node *head;
    Node *tail;
} List;

List *initList(void)
{
    List *llist = NULL;

    llist = (List *) malloc(sizeof(List));

    return llist;
}

void deleteList(List *llist)
{
    Node *ptr = NULL;
    Node *tmp = NULL;

    if(llist == NULL)
    {
        ptr = llist->head;
        llist->head = NULL;
        
        while(ptr != NULL)
        {
            tmp = ptr->next;
            free(ptr);
            ptr = tmp;
        }
    }
}

int insertNode(List *llist, int value)
{
    Node *newnode = NULL;
    int ret = 0;

    // Create new node
    newnode = (Node *) malloc(sizeof(Node));

    if(newnode == NULL)
    {
        printf("Failed to allocate memory for new node\n");
        ret = -1;
    }
    else
    {
        newnode->data = value;
    }

    return ret;
}

void traverseList(List *llist)
{
    printf("%s: enter\n", __FUNCTION__);
}

int main(void)
{
    printf("Link List Review\n");

    return 0;
}
