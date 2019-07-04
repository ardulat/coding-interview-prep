// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
    void visit(TreeNode* root, int k, int& count, int& res) {
        if (root != NULL && count < k) {
            visit(root->left, k, count, res);
            // visit the root node
            count++;
            if (count == k) {
                res = root->val;
                return;
            }
            visit(root->right, k, count, res);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int count = 0, res;
        visit(root, k, count, res);
        return res;
    }
};