// https://www.interviewbit.com/problems/path-sum/

int Solution::hasPathSum(TreeNode* A, int B) {
    if (A->left == NULL && A->right == NULL) { // if it is a leaf node
        if (B == A->val)
            return 1;
        else
            return 0;
    }
    
    int newSum = B - A->val;
    if ((A->left != NULL && hasPathSum(A->left, newSum))
        || (A->right != NULL && hasPathSum(A->right, newSum)))
        return 1;
    
    return 0;    
}