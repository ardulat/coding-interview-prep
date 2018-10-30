// https://www.interviewbit.com/problems/balanced-binary-tree/

int height(TreeNode* root) {
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right))+1;
}

int Solution::isBalanced(TreeNode* A) {
    if (A == NULL)
        return 1;
    if (abs(height(A->left)-height(A->right)) <= 1
        && isBalanced(A->left) && isBalanced(A->right))
        return 1;
    return 0;
}