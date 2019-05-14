// https://leetcode.com/problems/find-bottom-left-tree-value/

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
    int findBottomLeftValue(TreeNode* root) {
        // root is not null
        queue<TreeNode*> q, next;
        q.push(root);
        bool lastRow = false;
        int candidate = root->val;
        while (!lastRow) { // while it is not last row
            TreeNode* temp = q.front();
            q.pop();
            if (temp->left != NULL)
                next.push(temp->left);
            if (temp->right != NULL)
                next.push(temp->right);
            // condition for last row
            if (next.empty() && q.empty())
                lastRow = true; // this will stop the loop
            if (!next.empty() && q.empty()) {
                q.swap(next); // next will be empty now
                candidate = q.front()->val; // the leftmost element
            }
        }
        return candidate;
    }
};