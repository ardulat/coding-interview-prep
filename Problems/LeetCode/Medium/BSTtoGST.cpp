// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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
    TreeNode* bstToGst(TreeNode* root) {
        if (root == NULL)
            return root;
        TreeNode* right = root;
        stack<TreeNode*> s;
        while (right != NULL) {
            s.push(right);
            right = right->right;
        }
        int sum = 0;
        while (!s.empty()) {
            TreeNode* temp = s.top();
            s.pop();
            sum += temp->val;
            temp->val = sum;
            if (temp->left != NULL) {
                TreeNode* left = temp->left;
                s.push(left);
                while (left->right != NULL) {
                    s.push(left->right);
                    left = left->right;
                }
            }
        }
        return root;
    }
};