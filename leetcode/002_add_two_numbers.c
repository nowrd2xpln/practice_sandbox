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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    unsigned int dgt_cnt = 0;
    unsigned int dgt_ttl = 0;
    unsigned int cf = 0;
    struct ListNode *l1_nd_ptr = l1;
    struct ListNode *l2_nd_ptr = l2;
    struct ListNode *l3_nd_ptr = NULL;
    struct ListNode *nd_ptr = NULL;
    struct ListNode *hd_nd_ptr = NULL;
    struct ListNode *new_nd = NULL;
    
    // Count digits
    while(l1_nd_ptr != NULL)
    {
        dgt_cnt++;
        printf("dgt_cnt = %d\n", dgt_cnt);
        
        // Also able to do allocation here as list buffer
        new_nd = (struct ListNode *) malloc(sizeof(struct ListNode));
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
        l1_nd_ptr = l1_nd_ptr->next;
    }
    
    printf("dgt_cnt %d\n\n", dgt_cnt);
    
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

  
  
  return 0;
}

