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
    //Either return the distance of it or -1 if its not balanced
    int balance(TreeNode* link)
    {
        //First check of the root is NULL, so basically return 0 if it is 
        if(link == NULL)
        {
            return 0;
        }    

        int left_height = balance(link->left);
        int right_height = balance(link->right);

        
        if(left_height == -1 || right_height == -1)
        {
            return -1;
        }

        if(abs(left_height - right_height) > 1)
        {
            return -1;
        }

        return ((max(left_height , right_height)) + 1);


    }
    bool isBalanced(TreeNode* root) {
            

        return ((balance(root) == -1) ? false : true);
        
        
    }
};
