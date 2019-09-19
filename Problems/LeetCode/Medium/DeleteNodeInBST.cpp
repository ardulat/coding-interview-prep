// https://leetcode.com/problems/delete-node-in-a-bst/

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // step 0: base case
        if (root == NULL)
            return root;
        
        TreeNode *tempRoot = new TreeNode(0);
        tempRoot->right = root;
        
        // step 1: search the parent node
        TreeNode *parent = tempRoot;
        TreeNode *node = root; // child node or node of interest to delete
        
        while (node->val != key) {
            // otherwise move further
            parent = node;
            if (node->val < key) // move right
                node = node->right;
            else
                node = node->left;
            
            // no such value exists
            if (node == NULL)
                return root;
        }

        TreeNode *child;
        
        // step 2.1: the node has no children
        if (node->left == NULL && node->right == NULL)
            child = NULL;

        // step 2.2: the node has two children
        else if (node->left != NULL && node->right != NULL) {
            // find leftmost in the right subtree
            TreeNode *p = node;
            child = node->right;
            
            while (child->left != NULL) {
                p = child; // parent of that child
                child = child->left;
            }
            
            // losing children of child
            child->left = node->left;
            if (child != node->right) {
                p->left = child->right; // don't lose your children anymore
                child->right = node->right;
            }
        }

        // step 2.3: the node has one child
        else
            child = node->left != NULL ? node->left : node->right;
        
        if (parent->left == node)
            parent->left = child;
        else
            parent->right = child;
        
        return tempRoot->right;
    }
};