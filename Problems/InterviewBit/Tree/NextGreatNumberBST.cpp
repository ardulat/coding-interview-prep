// https://www.interviewbit.com/problems/next-greater-number-bst/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* find(TreeNode* root, int data) {
    if (root == NULL)
        return root;
    while (root->val != data) {
        if (root->val < data)
            root = root->right;
        else
            root = root->left;
    }
    return root;
}

TreeNode* Solution::getSuccessor(TreeNode* A, int B) {
    // search the node
    TreeNode* current = find(A, B);
    if (current == NULL)
        return current;
    // case 1: node has right subtree
    if (current->right != NULL) {
        TreeNode* temp = current->right;
        while (temp->left != NULL)
            temp = temp->left;
        return temp;
    }
    // case 2: no right subtree
    else {
        TreeNode* successor = NULL;
        TreeNode* ancestor = A;
        while (ancestor != current) {
            if (current->val < ancestor->val) {
                successor = ancestor; // the deepest left node
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}
