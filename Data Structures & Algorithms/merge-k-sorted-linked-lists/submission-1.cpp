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

    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        ListNode* head = NULL;
        ListNode* curr = NULL;

        if(curr1 == NULL && curr2 != NULL)
        {
            return curr2;
        }
        else if((curr1 != NULL && curr2 == NULL))
        {
            return curr1;
        }
        else if((curr1 == NULL && curr2 == NULL))
        {
            return NULL;
        }


        while((curr1 != NULL) && (curr2 != NULL))
        {
            if(curr1->val <= curr2->val)
            {
                if(head == NULL)
                {
                    head = curr1;
                    curr = curr1;
                } 
                else
                {
                    curr->next = curr1;
                    curr = curr1;
                }
                curr1 = curr1->next;                
            }
            else
            {
                if(head == NULL)
                {
                    head = curr2;
                    curr = curr2;
                }
                else
                {
                    curr->next = curr2;
                    curr = curr2;
                }
                
                curr2 = curr2->next;                
            }
        }

        if(curr1 != NULL)
        {
            curr->next = curr1;
        }
        else
        {
            curr->next = curr2;
        }

        return head;
    }

        // Recursively merge the first k lists
    ListNode* mergeK(vector<ListNode*>& lists, int left, int right)
    {
        // Base case: only one list
        if (left == right)
            return lists[left];

        // No lists in this range
        if (left > right)
            return NULL;

        int mid = left + (right - left) / 2;

        // Recursively merge the left half
        ListNode* head1 = mergeK(lists, left, mid);

        // Recursively merge the right half
        ListNode* head2 = mergeK(lists, mid + 1, right);

        // Merge the two halves
        return merge(head1, head2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        if (k == 0)
            return NULL;

        return mergeK(lists,0, k-1);
    }
};
