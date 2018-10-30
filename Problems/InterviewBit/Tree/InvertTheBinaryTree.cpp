// https://www.interviewbit.com/problems/invert-the-binary-tree/

// Too easy?

TreeNode* Solution::invertTree(TreeNode* A) {
    if (A == NULL)
        return NULL;
    if (A->left != NULL)
        A->left = invertTree(A->left);
    if (A->right != NULL)
        A->right = invertTree(A->right);
    TreeNode* temp = A->left;
    A->left = A->right;
    A->right = temp;
    return A;
}