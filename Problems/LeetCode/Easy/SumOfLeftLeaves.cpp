// https://leetcode.com/problems/sum-of-left-leaves/

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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        int left = sumOfLeftLeaves(root->left);
        int right = sumOfLeftLeaves(root->right);
        int sum = left+right;
        if (root->left != NULL &&
            root->left->left == NULL &&
            root->left->right == NULL)
            sum += root->left->val;
        return sum;
    }
};