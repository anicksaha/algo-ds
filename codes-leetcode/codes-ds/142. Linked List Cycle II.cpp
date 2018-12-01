/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getLoopHead(ListNode *head, ListNode *ptr_in_loop) {
        ListNode *ptr1 = ptr_in_loop;
        ListNode *ptr2 = ptr_in_loop;
        
        // Count the number of nodes in loop 
        int k = 1; 
        while (ptr1->next != ptr2) { 
            ptr1 = ptr1->next; 
            k++; 
        } 
  
        // Fix one pointer to head 
        ptr1 = head; 
  
        // And the other pointer to k nodes after head 
        ptr2 = head; 
        for (int i=0;i<k;i++) 
            ptr2 = ptr2->next; 
  
        /*  Move both pointers at the same pace, 
        they will meet at loop starting node */
        while (ptr2 != ptr1) { 
            ptr1 = ptr1->next; 
            ptr2 = ptr2->next; 
        }
        
        return ptr1;
    }
    
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow_p = head;
        ListNode* fast_p = head; 
   
        while (slow_p && fast_p && fast_p->next ) { 
            slow_p = slow_p->next; 
            fast_p  = fast_p->next->next; 
            if(slow_p == fast_p) { 
                return getLoopHead(head,slow_p);
            } 
        } 
        return NULL;
    }
};