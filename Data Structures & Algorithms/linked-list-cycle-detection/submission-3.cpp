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
Method 1 : Add everything to hashmap with address and data if address and data already present then it is a cycle
Method 2 : Fast pointer and slow pointer
*/
class Solution {
public:
    bool hasCycle(ListNode* head) {

        if(head == NULL)
        {
            return false;
        }

        ListNode* fast_ptr = head;
        ListNode* slow_ptr = head;

        while(1)
        {
            if(fast_ptr->next == NULL || fast_ptr == NULL || slow_ptr->next == NULL || slow_ptr == NULL)
            {
                return false;
            }

            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;

            if(slow_ptr == fast_ptr)
            {
                break;
            }
        }
        return true;
    }
};
