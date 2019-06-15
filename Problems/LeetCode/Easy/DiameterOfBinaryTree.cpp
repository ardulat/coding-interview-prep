// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        int childDiameter = max(leftDiameter, rightDiameter);
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(childDiameter, leftDepth+rightDepth);
    }
};

// Same logic but you traverse each node once instead of twice

class Solution {
public:
    int maxDepth(TreeNode* root, int& ans) {
        if (root == NULL)
            return 0;
        int left = maxDepth(root->left,ans);
        int right = maxDepth(root->right,ans);
        ans = max(ans, left+right+1);
        return max(left, right)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 1;
        maxDepth(root, ans);
        return ans-1;
    }
};