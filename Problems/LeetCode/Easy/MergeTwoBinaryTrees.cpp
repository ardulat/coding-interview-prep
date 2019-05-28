// https://leetcode.com/problems/merge-two-binary-trees/

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
    1. t1 == NULL, t2 != NULL
    2. t1 != NULL, t2 == NULL
    3. t1 == t2 == NULL
    */
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // base case
        if (t1 == NULL && t2 == NULL)
            return NULL;
        else if (t1 == NULL && t2 != NULL)
            return t2;
        else if (t1 != NULL && t2 == NULL)
            return t1;
        
        TreeNode *root, *left, *right;
        root = new TreeNode(t1->val + t2->val);
        root->left = mergeTrees(t1->left, t2->left);
        root->right = mergeTrees(t1->right, t2->right);
        
        return root;
    }
};