// https://www.interviewbit.com/problems/postorder-traversal/

// postorder traversal using two stacks

vector<int> Solution::postorderTraversal(TreeNode* A) {
    TreeNode* current = A;
    stack<TreeNode*> first, second;
    vector<int> result;
    
    if (A == NULL)
        return result;
    first.push(current);
    
    while (!first.empty()) {
        current = first.top();
        first.pop();
        second.push(current);
        
        if (current->left != NULL)
            first.push(current->left);
        if (current->right != NULL)
            first.push(current->right);
    }
    
    while (!second.empty()) {
        current = second.top();
        second.pop();
        result.push_back(current->val);
    }
    return result;
}
