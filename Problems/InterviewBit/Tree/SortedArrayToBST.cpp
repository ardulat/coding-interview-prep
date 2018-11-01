// https://www.interviewbit.com/problems/sorted-array-to-balanced-bst/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* sortedArrayToBSTUtil(const vector<int> &A, int start, int end) {
    if (start > end)
        return NULL;
    
    int mid = (start+end)/2;
    TreeNode* root = new TreeNode(A[mid]);
    root->left = sortedArrayToBSTUtil(A, start, mid-1);;
    root->right = sortedArrayToBSTUtil(A, mid+1, end);
    
    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    TreeNode* root = sortedArrayToBSTUtil(A, 0, A.size()-1);
    
    return root;
}
