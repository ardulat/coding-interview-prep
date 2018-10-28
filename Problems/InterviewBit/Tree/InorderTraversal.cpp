// https://www.interviewbit.com/problems/inorder-traversal/

// Recursive would be easy
// We do iterative using stack here

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    TreeNode* current = A;
    stack<TreeNode*> s;
    vector<int> result;
    
    while (current != NULL || !s.empty()) {
        if (current != NULL) {
            s.push(current);
            current = current->left;
        }
        else {
            current = s.top();
            result.push_back(current->val);
            s.pop();
            current = current->right;
        }
    }
    return result;
}
