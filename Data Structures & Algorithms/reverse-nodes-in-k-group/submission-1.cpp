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
    ListNode* reverse_List(ListNode* prev , ListNode* curr, ListNode* forw, ListNode* tail)
    {
        while(curr != tail)
        {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (head == NULL || k <= 1)
        {
            return head;
        }

        ListNode* start = head;
        ListNode* tail = head;
        ListNode* prevGroupTail = NULL;
        bool first_flag = true;

        while (start != NULL)
        {
            tail = start;

            // Find the node after the current group
            for (int i = 0; i < k; i++)
            {
                if (tail == NULL)
                {
                    return head;
                }

                tail = tail->next;
            }

            ListNode* oldStart = start;

            start = reverse_List(tail, start, start->next, tail);

            if (first_flag)
            {
                head = start;
                first_flag = false;
            }
            else
            {
                prevGroupTail->next = start;
            }

            // Old start is now the tail of the reversed group
            prevGroupTail = oldStart;

            // Move to the next group
            start = tail;
        }

        return head;
    }
};
