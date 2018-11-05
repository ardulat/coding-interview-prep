// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> currentLevel, nextLevel;
        currentLevel.push(root);
        TreeNode* temp;
        vector<int> currentResult;
        vector<vector<int>> result;
        
        // base case:
        if (root == NULL)
            return result; // empty
        
        while (!currentLevel.empty()) {
            temp = currentLevel.front();
            currentLevel.pop();
            currentResult.push_back(temp->val);
            if (temp->left != NULL)
                nextLevel.push(temp->left);
            if (temp->right != NULL)
                nextLevel.push(temp->right);
            
            if (currentLevel.empty()) { // if it's empty after popping
                currentLevel.swap(nextLevel);
                result.push_back(currentResult);
                currentResult.clear();
            }
        }
        return result;
    }
};

