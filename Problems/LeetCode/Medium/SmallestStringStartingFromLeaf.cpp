// https://leetcode.com/problems/smallest-string-starting-from-leaf/

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
private:
    string smallest;
public:
    void dfs(TreeNode *root, vector<char> path) {
        if (root == NULL)
            return;
        path.push_back(root->val+'a');
        if (root->left == NULL && root->right == NULL) { // leaf node
            // construct a string
            string temp = "";
            for (char c : path)
                temp = c + temp;
            if (smallest.empty() || strcmp(temp.c_str(),smallest.c_str())<0)
                smallest = temp;
            return;
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, vector<char>());
        return smallest;
    }
};