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
        printf("%d ", nd->val);    
        nd = nd->next;
    }
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

        if(cf == 1)
        {
            sum++;
        }

        if(sum > 9)
        {
            cf = 1;
            sum %= 10;
        }
        else
        {
            cf = 0;
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
        //printf("sum dgt %p %d\n", l3_nd_ptr, sum);
        

        // Shift to next node
        if(l1_nd_ptr) 
        {
            l1_nd_ptr = l1_nd_ptr->next;
        }

        if(l2_nd_ptr) 
        {
            l2_nd_ptr = l2_nd_ptr->next;
        }

        if(cf == 1 && !l1_nd_ptr && !l2_nd_ptr)
        {
            l3_nd_ptr->next = (struct node *) malloc(sizeof(struct node));
            l3_nd_ptr = l3_nd_ptr->next;
            l3_nd_ptr->next = NULL;
            l3_nd_ptr->val = 1;
    
        }
    }


    return l3_nd_head;
}

int main(void)
{
    struct node nd3 = { 3, NULL };
    struct node nd2 = { 2, &nd3 };
    struct node nd1 = { 1, &nd2 };

    struct node nd5 = { 5, NULL };
    struct node nd4 = { 4, &nd5 };
	
    struct node nd6 = { 9, NULL };
    struct node nd7 = { 9, &nd6 };
    struct node nd8 = { 9, &nd7 };
    struct node nd9 = { 9, &nd8 };

    struct node *ans = NULL;

    // Testcase: Equal number of digits
    ans = addTwoNumbers(&nd2, &nd4);
    print_list(&nd2);
    printf(" + ");
    print_list(&nd4);
    printf(" = ");
    print_list(ans);
    printf("\n");
    
    // Testcase: Unequal number of digits
    ans = addTwoNumbers(&nd5, &nd1);
    print_list(&nd5);
    printf(" + ");
    print_list(&nd1);
    printf(" = ");
    print_list(ans);
    printf("\n");


    // Testcase: Unequal number of digits with Carry Over
    ans = addTwoNumbers(&nd9, &nd3);
    print_list(&nd9);
    printf(" + ");
    print_list(&nd3);
    printf(" = ");
    print_list(ans);
    printf("\n");

    return 0;
}

