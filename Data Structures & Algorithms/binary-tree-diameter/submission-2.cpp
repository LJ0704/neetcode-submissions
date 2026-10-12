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
    int findDepth(TreeNode* curr, int& diameter) {
        if (curr == nullptr) {
            return 0;
        }

        int leftDepth = findDepth(curr->left, diameter);
        int rightDepth = findDepth(curr->right, diameter);

        diameter = max(diameter, leftDepth + rightDepth);

        return max(leftDepth, rightDepth) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        
        findDepth(root, diameter);
        return diameter;
    }
};
