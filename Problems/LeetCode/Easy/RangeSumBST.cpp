// https://leetcode.com/problems/range-sum-of-bst/

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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (root == NULL)
            return 0;
        int left = rangeSumBST(root->left, L, R);
        int right = rangeSumBST(root->right, L, R);
        int sum = left + right;
        if (L <= root->val && root->val <= R)
            sum += root->val;
        return sum;
    }
};