// https://leetcode.com/problems/binary-tree-pruning/

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
    bool satisfy(TreeNode* root) {
        if (root == NULL)
            return true;
        if (root->val == 0 && satisfy(root->left) && satisfy(root->right))
            return true;
        return false;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if (satisfy(root))
            return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        return root;
    }
};