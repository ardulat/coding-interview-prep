// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    left = 2->3->4->NULL
    right = 5->6->NULL
    */
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        TreeNode *left = root->left, *right = root->right; // NULL, NULL
        flatten(left);
        flatten(right);
        if (left != NULL)
            root->right = left;
        else
            root->right = NULL;
        root->left = NULL;
        left = root; // do I rly need it?
        while (left->right != NULL)
            left = left->right;
        left->right = right;
    }
};