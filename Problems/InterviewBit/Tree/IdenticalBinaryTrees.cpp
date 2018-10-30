// https://www.interviewbit.com/problems/identical-binary-trees/

int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if (A == NULL && B == NULL)
        return 1;
    if (A != NULL && B != NULL)
        if (A->val == B->val)
            if (isSameTree(A->left, B->left)
                && isSameTree(A->right, B->right))
                return 1;
    return 0;
}