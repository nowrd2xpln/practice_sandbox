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
    llist->head = NULL;
    llist->tail = NULL;
    llist->cnt = 0;

    return llist;
}

void deleteList(List *llist)
{
	Node *ptr = NULL;
	Node *tmp = NULL;

	printf("%s: enter\n", __FUNCTION__);

	if(llist != NULL) {		
 		ptr = llist->head;
 		llist->head = NULL;
        
 		while(ptr != NULL) {
 			tmp = ptr->next;
			printf("DeleteNode(%d): %p - %d\n", llist->cnt, ptr, ptr->data);

 			free(ptr);
			llist->cnt--;

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

	if(newnode == NULL) {
		printf("Failed to allocate memory for new node\n");
		ret = -1;
	}
	else {
		newnode->data = value;
	}

	newnode->next = llist->head;
	llist->head = newnode;
	llist->cnt++;

	printf("NewNode(%d): %p - %d\n", llist->cnt, llist->head, llist->head->data);

	return ret;
}

void traverseList(List *llist)
{
    printf("%s: enter\n", __FUNCTION__);
}

int main(void)
{
	List *L1 = NULL;

	printf("Link List Review\n");

	L1 = initList();
	insertNode(L1, 57);
	deleteList(L1);
    return 0;
}
