// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/

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
    int findMinGreater(TreeNode *root, int target) {
        if (root == NULL)
            return -1;
        if (root->val > target)
            return root->val;
        int left = findMinGreater(root->left, target);
        int right = findMinGreater(root->right, target);
        int minChild;
        if (left != -1 && right != -1) minChild = min(left, right);
        else if (left == -1) minChild = right;
        else if (right == -1) minChild = left;
        else minChild = -1;
        return minChild;
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        return findMinGreater(root, root->val);
    }
};