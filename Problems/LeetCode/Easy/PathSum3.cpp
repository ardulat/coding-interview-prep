// https://leetcode.com/problems/path-sum-iii/

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
    void dfs(TreeNode *root, int path, int sum, int& count) {
        if (root == NULL)
            return;
        path += root->val;
        if (path == sum)
            count++;
        dfs(root->left, path, sum, count);
        dfs(root->right, path, sum, count);
    }
    
    int pathSum(TreeNode* root, int sum) {
        int count = 0;
        if (root == NULL)
            return 0;
        dfs(root, 0, sum, count);
        count += pathSum(root->left, sum) + pathSum(root->right, sum);
        return count;
    }
};