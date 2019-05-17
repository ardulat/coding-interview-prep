// https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
    /*
    4 < 5
    */
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL)
            return new TreeNode(val);
        if (root->val < val) {
            if (root->right == NULL) {
                root->right = new TreeNode(val);
                return root;
            }
            insertIntoBST(root->right, val);
        } else {
            if (root->left == NULL) {
                root->left = new TreeNode(val);
                return root;
            }
            insertIntoBST(root->left, val);
        }
        return root;
    }
};