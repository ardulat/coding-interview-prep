// https://www.interviewbit.com/problems/valid-binary-search-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // Efficient solution in O(n)
 
int isBstUtil(TreeNode* root, int minValue, int maxValue) {
    if (root == NULL)
        return 1;
    if (root->val >= minValue && root->val < maxValue
        && isBstUtil(root->left, minValue, root->val)
        && isBstUtil(root->right, root->val, maxValue))
        return 1;
    return 0;
}
 
int Solution::isValidBST(TreeNode* A) {
    return isBstUtil(A, INT_MIN, INT_MAX);
}
