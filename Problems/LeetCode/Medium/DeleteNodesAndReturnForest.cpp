// https://leetcode.com/problems/delete-nodes-and-return-forest/

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
    /*
    - use hashtable to store the numbers in to_delete
    - traverse the tree in preorder
    - if node value is in the hasthable:
        -- add its children to disjoints sets result
        -- traverse them in recursion manner
        -- remove the node from the tree
    - otherwise, just skip it
    */
    void traverse(TreeNode *root, unordered_set<int>& table, vector<TreeNode*>& res, bool hasParent) {
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        if (left != NULL) {
            if (table.find(left->val) != table.end()) {
                traverse(left, table, res, false);
                root->left = NULL;
            }
            else {
                if (!hasParent)
                    res.push_back(left);
                traverse(left, table, res, true);
            }
        }
        if (right != NULL) {
            if (table.find(right->val) != table.end()) {
                traverse(right, table, res, false);
                root->right = NULL;
            }
            else {
                if (!hasParent)
                    res.push_back(right);
                traverse(right, table, res, true);
            }
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> table;
        // step 1: O(1) time to find the number exist in the list or not
        for (int num : to_delete)
            table.insert(num);
        // step 2: traverse the tree in recursion manner
        vector<TreeNode*> res;
        bool hasParent = true;
        
        if (root != NULL) {
            if (table.find(root->val) != table.end())
                hasParent = false;
            else
                res.push_back(root);
        }
        
        traverse(root, table, res, hasParent);
        
        return res;
    }
};