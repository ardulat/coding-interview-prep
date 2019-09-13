// https://leetcode.com/problems/path-sum/

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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        
        sum = sum - root->val;
        
        if (root->left == NULL && root->right == NULL) { // leaf node
            if (sum == 0)
                return true;
        }
        else {
            if (hasPathSum(root->left, sum))
                return true;
            if (hasPathSum(root->right, sum))
                return true;
        }
        return false;
    }
};