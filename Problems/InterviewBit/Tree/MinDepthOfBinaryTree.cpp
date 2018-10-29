// https://www.interviewbit.com/problems/min-depth-of-binary-tree/

int Solution::minDepth(TreeNode* A) {
    if (A->left != NULL && A->right != NULL) // both exist
        return min(minDepth(A->left), minDepth(A->right))+1;
    else if (A->left != NULL && A->right == NULL)
        return minDepth(A->left)+1;
    else if (A->right != NULL && A->left == NULL)
        return minDepth(A->right)+1;
    return 1;
}