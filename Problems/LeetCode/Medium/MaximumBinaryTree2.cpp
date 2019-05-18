// https://leetcode.com/problems/maximum-binary-tree-ii/

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
    Solution:
    - find the best position to insert the value
    - consider that it will be the rightmost element in the original array
    
    case 1 (base case):
    val > root->val
    root has to be the left child of val
    
    case 2 (recursion):
    val < root->val
    recur the function passing the right child
    update right child of the previous root
    */
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* newRoot = new TreeNode(val);
            return newRoot;
        }
        if (val > root->val) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        // val < root->val
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};