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

    TreeNode* invert(TreeNode* curr)
    {
        if(curr == NULL)
        {
            return NULL;
        }
        
        TreeNode* temp = curr->left;
        curr->left = curr->right;
        curr->right = temp;

        curr->left = invertTree(curr->left);
        curr->right = invertTree(curr->right);

        return curr;

    }

    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};
