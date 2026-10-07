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

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *link;

        if(head == NULL) 
        {
            return NULL;
        }

        while(curr->next != NULL)
        {
            link = curr->next;
            curr->next = prev;
            prev = curr;
            curr = link;
        }

        head = curr;
        curr->next = prev;

        return head;        
    }
};
