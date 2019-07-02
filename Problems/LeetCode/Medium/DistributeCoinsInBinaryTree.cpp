// https://leetcode.com/problems/distribute-coins-in-binary-tree/

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
    - count excess in the left subtree
    - count excess in the right subtree
    - count excess from the root as:   node.val+excess(left)+excess(right)-1
    - update the root node value to 1
    */
    int ans;
    
    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int excess = root->val + left + right - 1;
        ans += abs(left) + abs(right);
        return excess;
    }
    
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};