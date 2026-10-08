/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
Method 1 : Stack if n = 1 remove the first element that pops
Method 2 : Use two pointers with a gap of n + 1

*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       
       ListNode* tailing_ptr = head;
       ListNode* leading_ptr = head;


       while(n > 0 && leading_ptr != NULL)
       {
            leading_ptr = leading_ptr->next;
            n--;
       }

       if (leading_ptr == NULL) 
       {
           return head->next;
       }

       if(leading_ptr == NULL || n < 0)
       {
            return NULL;
       }else
       {
            while(leading_ptr->next != NULL)
            {
                tailing_ptr = tailing_ptr->next;
                leading_ptr = leading_ptr->next;
            }

            tailing_ptr->next = tailing_ptr->next->next;
       }
        return head;
    }
};
