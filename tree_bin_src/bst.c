#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
    int data;
    Node *lft;
    Node *rht;
};

Node *newNode(int data)
{
    Node *tmp = NULL;
    
    tmp = (Node *) malloc(sizeof(Node));
    if(tmp == NULL) {
        printf("Failed to allocate memory!\n");
    }
    else {
        tmp->data = data;
    }
    
    return tmp;
}

Node *findMin(Node *node)
{
    if(node == NULL) {
        // No element in the tree
        return NULL;
    }
    
    if(node->lft) {
        return findMin(node->lft);
    }
    else {
        return node;
    }
}

Node *findMax(Node *node)
{
    if(node == NULL) {
        return NULL;
    }

    if(node->rht) {
        return findMax(node->rht);
    }
    else
        return node;
}

Node *insertNode(Node *root, int data)
{
    Node *cur = root;
    
    // Empty tree
    if(cur == NULL) {
        cur = newNode(data);
        return;
    }
    
    if(data < cur->data) {
        cur->lft = insertNode(cur->lft, data);
        printf("insert lft\n");
    }
    else if(data > cur->data) {
        cur->rht = insertNode(cur->rht, data);
        printf("insert rht\n");
    }
    
    return cur;
}

Node *deleteNode(Node *node, int data)
{
    Node *temp = NULL;

    if(node == NULL) {
        printf("Node not found\n");
    }
    else if(data < node->data)
    {
        node->lft = deleteNode(node->lft, data);
    }
    else if(data > node->data)
    {
        node->rht = deleteNode(node->rht, data);
    }
    else
    {
        if(node->rht && node->lft) {
            temp = findMin(node->rht);
            node->data = temp->data;

            node->rht = deleteNode(node->rht, temp->data);
        }
        else {
            temp = node;
            if(node->lft == NULL) {
                node = node->rht;
            }
            else if(node->rht == NULL) {
                node = node->lft;
            }

            printf("Deleting %d - %p\n", temp->data, temp);
            free(temp);
        }
    }

    return node;
}

void traverse(Node *node)
{
    if(node == NULL) {
        return;
    }
    
    traverse(node->lft);
    printf("%d- - %p\n", node->data, node);
    traverse(node->rht);
}

int main()
{
    printf("Hello, World!\n");

    Node *rt = NULL;
    
    rt = insertNode(rt, 57);
    rt = insertNode(rt, 58);
    rt = insertNode(rt, 56);
    traverse(rt);
    rt = deleteNode(rt, 56);
    if(rt == NULL) {
        printf("rt null\n");
    }
    traverse(rt);
    rt = deleteNode(rt, 58);
    traverse(rt);
    
    
    return 0;
}
