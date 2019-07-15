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
    bool hasPathSum(TreeNode *root, int path, int& sum) {
        path += root->val;
        if (root->left == NULL && root->right == NULL) {
            if (path == sum)
                return true;
        }
        else {
            if (root->left != NULL && hasPathSum(root->left, path, sum))
                return true;
            if (root->right != NULL && hasPathSum(root->right, path, sum))
                return true;
        }
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        return root == NULL ? false : hasPathSum(root, 0, sum);
    }
};