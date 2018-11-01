// https://www.interviewbit.com/problems/kth-smallest-element-in-tree/

// Approach: use inorder traversal

int Solution::kthsmallest(TreeNode* A, int B) {
    TreeNode* current = A;
    stack<TreeNode*> s;
    int count = 0;
    while (current != NULL || !s.empty()) {
        if (current != NULL) {
            s.push(current);
            current = current->left;
        }
        else {
            count++;
            current = s.top();
            s.pop();
            if (count == B)
                return current->val;
            current = current->right;
        }
    }
}
