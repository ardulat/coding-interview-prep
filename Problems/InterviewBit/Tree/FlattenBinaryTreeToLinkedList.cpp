// https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/

TreeNode* Solution::flatten(TreeNode* A) {
    // base case:
    if (A == NULL)
        return NULL;
    TreeNode* temp = A, *leftSubtree = A->left, *rightSubtree = A->right;
    leftSubtree = flatten(leftSubtree);
    rightSubtree = flatten(rightSubtree);
    
    temp->left = NULL;
    temp->right = leftSubtree;
    // go to the end of the left subtree
    while (temp->right != NULL)
        temp = temp->right;
    temp->right = rightSubtree;
    
    return A;
}
