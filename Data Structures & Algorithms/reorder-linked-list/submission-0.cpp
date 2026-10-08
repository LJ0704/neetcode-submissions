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
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        ListNode* slow = head;
        ListNode* fast = head;
        

        //Fast Pointer & slow pointer to find Mid
        while(fast != NULL && fast->next !=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow;

        //Reverse the second half of the linked list
        curr = mid->next;
        ListNode* prev = NULL;
        ListNode* future = curr->next;

        while(curr != NULL)
        {
           future = curr->next;
           curr->next = prev;
           prev = curr;
           curr = future;
                      
        }

        mid->next = NULL;   // fix 1: terminate the first half
        mid = prev;         // head of the reversed half
        curr = head;

        // Merge
        while (mid != NULL) {
            ListNode* temp = curr->next;
            ListNode* midNext = mid->next;   // fix 2: save before overwriting
            curr->next = mid;
            mid->next = temp;
            curr = temp;
            mid = midNext;
        }

        

    }
};
