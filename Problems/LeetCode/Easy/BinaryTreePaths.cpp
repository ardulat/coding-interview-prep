// https://leetcode.com/problems/binary-tree-paths/

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
    void binaryTreePathsUtil(TreeNode *root, string path, vector<string>& res) {
        path += to_string(root->val);
        
        if (root->left == NULL && root->right == NULL) { // leaf node
            res.push_back(path);
            return;
        }
        path += "->";
        if (root->left != NULL)
            binaryTreePathsUtil(root->left, path, res);
        if (root->right != NULL)
            binaryTreePathsUtil(root->right, path, res);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        
        // edge case root == null
        if (root == NULL) return res;
        
        binaryTreePathsUtil(root, "", res);
        
        return res;
    }
};