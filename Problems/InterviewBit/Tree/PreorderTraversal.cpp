// https://www.interviewbit.com/problems/preorder-traversal/

// Using stacks is easy!

vector<int> Solution::preorderTraversal(TreeNode* A) {
    TreeNode* current = A;
    stack<TreeNode*> s;
    vector<int> result;
    
    while (current != NULL || !s.empty()) {
        if (current != NULL) {
            result.push_back(current->val);
            s.push(current);
            current = current->left;
        }
        else {
            current = s.top();
            s.pop();
            current = current->right;
        }
    }
    return result;
}
