// https://leetcode.com/problems/find-duplicate-subtrees/

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
    string preorder(TreeNode* root, unordered_map<string,vector<TreeNode*>>& hashmap) {
        if (root == NULL)
            return "#";
        string s = to_string(root->val) +
            preorder(root->left, hashmap) +
            preorder(root->right, hashmap);
        
        hashmap[s].push_back(root);
        
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> hashmap;
        
        preorder(root, hashmap);
        
        vector<TreeNode*> res;
        
        for (auto pr : hashmap)
            if (pr.second.size() > 1)
                res.push_back(pr.second[0]);
        
        return res;
    }
};