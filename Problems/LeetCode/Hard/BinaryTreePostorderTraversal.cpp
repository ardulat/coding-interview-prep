// https://leetcode.com/problems/binary-tree-postorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        
        stack<TreeNode*> st;
        
        while (root != NULL || !st.empty()) {
            while (root != NULL) {
                if (root->right != NULL)
                    st.push(root->right);
                st.push(root);
                root = root->left;
            }
            
            root = st.top();
            st.pop();
            
            TreeNode *top = st.empty() ? NULL : st.top();
            if (root->right != NULL && top == root->right) {
                st.pop();
                st.push(root);
                root = root->right;
            }
            else {
                res.push_back(root->val);
                root = NULL;
            }
        }
        
        return res;
    }
};