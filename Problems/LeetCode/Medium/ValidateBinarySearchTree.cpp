// https://leetcode.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        TreeNode *left = root->left, *right = root->right;
        // both subtrees must be valid BSTs
        if (!isValidBST(left) || !isValidBST(right))
            return false;
        // rightmost value of the left subtree
        if (left != NULL) {
            while (left->right != NULL)
                left = left->right;
            if (left->val >= root->val)
                return false;
        }
        // leftmost value of the right subtree
        if (right != NULL) {
            while (right->left != NULL)
                right = right->left;
            if (right->val <= root->val)
                return false;
        }
        return true;
    }
};