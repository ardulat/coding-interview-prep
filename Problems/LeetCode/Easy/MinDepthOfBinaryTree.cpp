// https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL & root->right == NULL) // leaf node
            return 1;
        int left = INT_MAX, right = INT_MAX;
        if (root->left != NULL)
            left = minDepth(root->left);
        if (root->right != NULL)
            right = minDepth(root->right);
        return 1 + min(left, right);
    }
};