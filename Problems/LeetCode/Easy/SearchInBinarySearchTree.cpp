// https://leetcode.com/problems/search-in-a-binary-search-tree/

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || val == root->val)
            return root;
        if (val < root->val && root->left != NULL)
            return searchBST(root->left, val);
        if (val > root->val && root->right != NULL)
            return searchBST(root->right, val);
        return NULL;
    }
};