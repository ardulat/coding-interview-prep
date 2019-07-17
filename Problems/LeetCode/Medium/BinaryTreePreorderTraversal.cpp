// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    /*
    preorder:
    - root
    - root->left
    - root->right
    */
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *temp = st.top();
            st.pop();
            if (temp != NULL) {
                st.push(temp->right);
                st.push(temp->left);
                res.push_back(temp->val);
            }
        }
        return res;
    }
};