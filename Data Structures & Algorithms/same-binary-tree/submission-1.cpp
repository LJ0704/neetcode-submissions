/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int traverse_Tree(TreeNode* node1, TreeNode* node2)
    {
        if(node1 != NULL && node2 == NULL)
        {
            return -1;
        }
        if(node1 == NULL && node2 != NULL)
        {
            return -1;
        }
        if(node1 == NULL || node2 == NULL)
        {
            return 1; 
        }

        if(node1->val != node2->val)
        {
            return -1;
        }

        if((traverse_Tree(node1->left, node2->left)  == -1 ) || (traverse_Tree(node1->right, node2->right) == -1))
        {
            return -1;
        }

        return 1;        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return (traverse_Tree(p,q) == -1 ? false : true);
    }
};
