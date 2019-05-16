// https://leetcode.com/problems/balanced-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int depth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        int left = depth(root->left), right = depth(root->right);
        if (abs(left-right) <= 1 &&
            isBalanced(root->left) && 
            isBalanced(root->right))
            return true;
        return false;
    }
};