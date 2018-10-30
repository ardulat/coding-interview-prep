// https://www.interviewbit.com/problems/symmetric-binary-tree/

// Used prior knowledge gained from solved problems
 
TreeNode* invert(TreeNode* root) {
    if (root == NULL)
        return NULL;
    if (root->left != NULL)
        root->left = invert(root->left);
    if (root->right != NULL)
        root->right = invert(root->right);
    // swap left and right
    TreeNode* temp = root->right;
    root->right = root->left;
    root->left = temp;
    
    return root;
}

int identical(TreeNode* A, TreeNode* B) {
    if (A == NULL && B == NULL)
        return 1;
    
    if (A != NULL && B != NULL)
        if (A->val == B->val)
            if (identical(A->left, B->left)
                && identical(A->right, B->right))
                return 1;
    return 0;
}
 
int Solution::isSymmetric(TreeNode* A) {
    if (A == NULL)
        return 1;
    if (A->right == NULL && A->left == NULL)
        return 1;
    TreeNode* invertedRight = NULL;
    int areIdentical = 0;
    if (A->right != NULL)
        invertedRight = invert(A->right);
    if (A->left != NULL)
        areIdentical = identical(A->left, invertedRight);
    return areIdentical;
}
