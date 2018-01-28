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
    
    printf("Adding digits\n");

    // Check list counts
    while(l1_nd_ptr || l2_nd_ptr)
    { 
        if(l1_nd_ptr) 
        {
            l1_dgt_cnt++;
            l1_nd_ptr = l1_nd_ptr->next;
        }
        if(l2_nd_ptr) 
        {
            l2_dgt_cnt++;
            l2_nd_ptr = l2_nd_ptr->next;
        }
    }

    printf("l1 %d\n", l1_dgt_cnt);
    printf("l2 %d\n", l2_dgt_cnt);
        
    if(l1_dgt_cnt && l2_dgt_cnt)
    {
        l3_nd_head = (struct node *) malloc(sizeof(struct node));
        l3_nd_ptr = l3_nd_head;
    }

    l1_nd_ptr = l1;
    l2_nd_ptr = l2;

    while(l1_nd_ptr || l2_nd_ptr)
    { 
        printf("%02d: %p %p\n", ++iter, l1_nd_ptr, l2_nd_ptr);

        
        // Add cases
        if(l1_nd_ptr && l2_nd_ptr)
        {
            printf("both: %d\n", l1_nd_ptr->val + l2_nd_ptr->val);
            sum = l1_nd_ptr->val + l2_nd_ptr->val;
        }
        else if(l1_nd_ptr && !l2_nd_ptr)
        {
            printf("l1 only: %d\n", l1_nd_ptr->val);
            sum = l1_nd_ptr->val;
        }
        else if(!l1_nd_ptr && l2_nd_ptr)    
        {
            printf("l2 only: %d\n", l2_nd_ptr->val);
            sum = l2_nd_ptr->val;
        }


        if(iter == 1)
        {
            l3_nd_head = (struct node *) malloc(sizeof(struct node));
            l3_nd_ptr = l3_nd_head;
            l3_nd_ptr->next = NULL;
        } 
        else
        {
            l3_nd_ptr->next = (struct node *) malloc(sizeof(struct node));
            l3_nd_ptr->next->next = NULL;
        }
            l3_nd_ptr->val = sum;

        if(l1_nd_ptr) 
        {
            l1_nd_ptr = l1_nd_ptr->next;
        }

        if(l2_nd_ptr) 
        {
            l2_nd_ptr = l2_nd_ptr->next;
        }
        
    }

    return NULL;

    // Count digits
    while(!l1_nd_ptr && !l2_nd_ptr)
    {
        dgt_cnt++;



        printf("dgt_cnt = %d\n", dgt_cnt);
        
        // Also able to do allocation here as list buffer
        new_nd = (struct node *) malloc(sizeof(struct node));
        printf("new node: %p\n", new_nd);
        
        // check for valid memory allocation
        if(new_nd == NULL)
        {
            printf("nd_ptr NULL bad malloc()\n");
        }
        
        // Insert node into l3 buffer
        new_nd->next = hd_nd_ptr;
        hd_nd_ptr = new_nd;
     
        printf("%p->%d :%p->%p\n", new_nd, new_nd->val, new_nd, new_nd->next);
        // Move  pointer to next node
        
        if(l1_nd_ptr != NULL)
        {
            l1_nd_ptr = l1_nd_ptr->next;
            l1_dgt_cnt++;
        }

        if(l2_nd_ptr != NULL)
        {
            l2_nd_ptr = l2_nd_ptr->next;
            l2_dgt_cnt++;
        }
    }
    
    printf("dgt_cnt %d\n\n", dgt_cnt);
    printf("l1_dgt_cnt %d\n\n", l1_dgt_cnt);
    printf("l2_dgt_cnt %d\n\n", l2_dgt_cnt);

    exit(0);

    // Initialize list pointers
    dgt_cnt = 0;
    l1_nd_ptr = l1;
    l2_nd_ptr = l2;
    l3_nd_ptr = hd_nd_ptr;
    
    printf("hd_nd_ptr %p\n", hd_nd_ptr);
    
    while(l1_nd_ptr != NULL)
    {
        // Check for carry flag from previous iteration
        if(cf == 1)
        {
            printf("CF detected\n");
            dgt_ttl++;
            cf = 0;
        }
        
        // Add digit
        dgt_ttl += l1_nd_ptr->val + l2_nd_ptr->val;
        
        // Check for carry
        if(dgt_ttl > 9)
        {
            cf = 1;
            dgt_ttl -= 10;
        }
        l3_nd_ptr->val = dgt_ttl;
        
        printf("%d + %d = ", l1_nd_ptr->val, l2_nd_ptr->val);
        printf("%d\n", dgt_ttl);
        printf("l3_nd_ptr->val %d\n\n============\n", l3_nd_ptr->val);
        
        l1_nd_ptr = l1_nd_ptr->next;
        l2_nd_ptr = l2_nd_ptr->next;
        l3_nd_ptr = l3_nd_ptr->next;
        dgt_ttl = 0;
    }
    
    return hd_nd_ptr;
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

    l1.cnt = list_count(&l1);

    l2.cnt = list_count(&l2);
    
    addTwoNumbers(l1.head, l2.head);
    
    return 0;
}

