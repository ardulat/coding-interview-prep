// https://leetcode.com/problems/path-sum-ii/

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
    void pathSum(TreeNode *root, int path, int& sum, vector<int> nodes, vector<vector<int>>& res) {
        path += root->val;
        nodes.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (path  == sum) {
                res.push_back(nodes);
                return;
            }
        }
        else {
            if (root->left != NULL)
                pathSum(root->left, path, sum, nodes, res);
            if (root->right != NULL)
                pathSum(root->right, path, sum, nodes, res);
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        pathSum(root, 0, sum, vector<int>(), res);
        return res;
    }
};