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
    ListNode* reverseList(ListNode* head) {

        if (!head || !head->next) return head;
        
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = head->next;
        curr->next = NULL;
        
        while(next->next != NULL)
        {
            curr->next = prev;
            prev = curr;            
            curr = next;
            next = curr->next;
        }
        curr->next = prev;
        prev = curr;
        next->next = prev;
        head = next;

        return head;
        
    }
};
