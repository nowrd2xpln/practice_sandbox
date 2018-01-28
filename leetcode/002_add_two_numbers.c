#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** @brief Takes a string and reverses the order of
 *         characters.
 *
 *  @param s The input string to be reversed
 *         row will be written.
 *
 *  @return void.
 */


// Definition for singly-linked list.
struct node {
    int val;
    struct node *next;
};

struct list {
    struct node *head;
    struct node *msd;
    unsigned int cnt;
};

void print_list(struct node *nd)
{
    struct node *curr = nd;

    while(nd != NULL)
    {
        printf("%d", nd->val);    
        nd = nd->next;
    }
    
    printf("\n");
}

unsigned int list_count(struct list *list)
{
    unsigned int cnt = 0;
    struct node *curr = list->head;

    printf("ENTER\n");

    while( curr != NULL) {
        cnt++;
        curr = curr->next;
    }

    return cnt;
}

struct node* addTwoNumbers(struct node* l1, struct node* l2) {
    unsigned int dgt_cnt = 0;
    unsigned int l1_dgt_cnt = 0;
    unsigned int l2_dgt_cnt = 0;
    unsigned int dgt_ttl = 0;
    unsigned int cf = 0;
    unsigned int iter = 0;
    unsigned int sum = 0;
    struct node *l1_nd_ptr = l1;
    struct node *l2_nd_ptr = l2;
    struct node *l3_nd_ptr = NULL;
    struct node *l3_nd_head = NULL;
    struct node *nd_ptr = NULL;
    struct node *hd_nd_ptr = NULL;
    struct node *new_nd = NULL;
    
    if(l1_dgt_cnt && l2_dgt_cnt)
    {
        l3_nd_head = (struct node *) malloc(sizeof(struct node));
        l3_nd_ptr = l3_nd_head;
    }

    l1_nd_ptr = l1;
    l2_nd_ptr = l2;

    while(l1_nd_ptr || l2_nd_ptr)
    { 
        // Counter interations
        ++iter;

        // Adding scenarios
        if(l1_nd_ptr && l2_nd_ptr)
        {
            sum = l1_nd_ptr->val + l2_nd_ptr->val;
        }
        else if(l1_nd_ptr && !l2_nd_ptr)
        {
            sum = l1_nd_ptr->val;
        }
        else if(!l1_nd_ptr && l2_nd_ptr)    
        {
            sum = l2_nd_ptr->val;
        }

        // Node allocation 
        if(iter == 1) // First digit
        {
            l3_nd_head = (struct node *) malloc(sizeof(struct node));
            l3_nd_ptr = l3_nd_head;
            l3_nd_ptr->next = NULL;
        } 
        else // Subsequest digits
        {
            l3_nd_ptr->next = (struct node *) malloc(sizeof(struct node));
            l3_nd_ptr = l3_nd_ptr->next;
            l3_nd_ptr->next = NULL;
        }

        // Assign sum 
        l3_nd_ptr->val = sum;
        printf("sum dgt %p %d\n", l3_nd_ptr, sum);
        

        // Shift to next node
        if(l1_nd_ptr) 
        {
            l1_nd_ptr = l1_nd_ptr->next;
        }

        if(l2_nd_ptr) 
        {
            l2_nd_ptr = l2_nd_ptr->next;
        }
        
    }


    print_list(l3_nd_head);

    return l3_nd_head;
}

int main(void)
{
    struct node nd3 = { 3, NULL };
    struct node nd2 = { 2, &nd3 };
    struct node nd1 = { 1, &nd2 };

    struct node nd5 = { 5, NULL };
    struct node nd4 = { 4, &nd5 };
	
    struct list l1 = { &nd1, 0 };
    struct list l2 = { &nd4, 0 };

    struct node *ans = NULL;

    // Testcase: Equal number of digits
    ans = addTwoNumbers(&nd2, &nd4);
    
    // Testcase: Unequal number of digits
    ans = addTwoNumbers(&nd5, &nd1);

    return 0;
}

