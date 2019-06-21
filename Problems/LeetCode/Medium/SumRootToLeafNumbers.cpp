// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    void sumUtil(TreeNode* root, int& sum, int number) {
        number = number*10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += number;
            return;
        }
        if (root->left != NULL)
            sumUtil(root->left, sum, number);
        if (root->right != NULL)
            sumUtil(root->right, sum, number);
    }
    
    int sumNumbers(TreeNode* root) {
        int sum = 0, number = 0;
        if (root != NULL)
            sumUtil(root, sum, number);
        return sum;
    }
};