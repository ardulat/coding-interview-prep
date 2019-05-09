// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        // always add such base case
        if (root == NULL)
            return res;
        TreeNode *left = root->left, *temp;
        stack<TreeNode*> st;
        
        st.push(root);
        while (left != NULL) {
            st.push(left);
            left = left->left;
        }
        
        while (!st.empty()) {
            temp = st.top();
            st.pop();
            res.push_back(temp->val);
            
            if (temp->right != NULL) {
                st.push(temp->right);
                left = temp->right->left;
                while (left != NULL) {
                    st.push(left);
                    left = left->left;
                }
            }
        }
        
        return res;
    }
};