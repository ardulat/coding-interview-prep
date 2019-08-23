// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

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
    Brute-force: O(N^2) time, O(1) space
    - find the max depth of the tree
    - find the parent node of nodes in the max depth
    
    Optimized:
    - combine two steps above
    
    - comment: we can not combine because first goes from bottom to top, the second step goes from top to bottom
    */
    int findMaxDepth(TreeNode *root) {
        // base case
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;
        
        int left = findMaxDepth(root->left);
        int right = findMaxDepth(root->right);
        
        return max(left, right) + 1;
    }
    
    void findParentDepth(TreeNode *root, int& depth, int current, TreeNode *&deep) {
        // base cases
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
            return;
        
        int left = findMaxDepth(root->left);
        int right = findMaxDepth(root->right);
        
        if (left == depth-current && right == depth-current) {
            deep = root;
        }
        else if (left == depth-current) {
            deep = root->left;
            findParentDepth(root->left, depth, current+1, deep);
        }
        else if (right == depth-current) {
            deep = root->right;
            findParentDepth(root->right, depth, current+1, deep);
        }
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int depth = findMaxDepth(root);
        
        if (depth == 1)
            return root;
        
        TreeNode *deep = root;
        
        findParentDepth(root, depth, 1, deep);
        
        return deep;
    }
};