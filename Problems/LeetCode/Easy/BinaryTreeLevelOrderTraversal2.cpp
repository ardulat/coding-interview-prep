// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == NULL)
            return vector<vector<int>>();
        stack<vector<int>> st;
        queue<TreeNode*> q, next;
        q.push(root);
        vector<int> lvl;
        lvl.push_back(root->val);
        st.push(lvl);
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left != NULL)
                next.push(temp->left);
            if (temp->right != NULL)
                next.push(temp->right);
            
            if (q.empty() && !next.empty()) {
                q = next;
                lvl = vector<int>(); // empty vector
                while (!next.empty()) {
                    lvl.push_back(next.front()->val);
                    next.pop();
                }
                st.push(lvl);
            }
        }
        
        vector<vector<int>> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};