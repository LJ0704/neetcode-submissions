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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* curr = &dummy;

        if(curr1 == NULL || curr2 == NULL)
        {
            return NULL;
        }       

        int sum = 0;
        int carry = 0;
        while(curr1 != NULL && curr2 != NULL)
        {
            int total = curr1->val + curr2->val + carry;
            sum = (total % 10);
            carry = (total / 10);  

            curr->next = new ListNode(sum);
            curr = curr->next;
            curr2 = curr2->next;
            curr1 = curr1->next;
        }

        while(curr1 != NULL)
        {
            int total = curr1->val + carry;
            sum = (total % 10);
            carry = (total / 10);  
            curr->next = new ListNode(sum);
            curr = curr->next;
            curr1 = curr1->next;
        }

      
        while(curr2 != NULL)
        {
            int total = curr2->val + carry;
            sum = (total % 10);
            carry = (total / 10);  
            curr->next = new ListNode(sum);
            curr = curr->next;           
            curr2 = curr2->next;
        }
        
        if(carry == 1)
        {
            curr->next = new ListNode(carry);
            curr = curr->next;
        }
        return dummy.next;
    }
};
