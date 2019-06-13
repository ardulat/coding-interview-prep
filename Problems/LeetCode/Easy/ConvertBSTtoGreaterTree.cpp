// https://leetcode.com/problems/convert-bst-to-greater-tree/

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
    void convertBST(TreeNode* root, int& sum) {
        if (root == NULL)
            return;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        convertBST(right, sum);
        sum += root->val;
        root->val = sum;
        convertBST(left, sum);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convertBST(root, sum);
        return root;
    }
};