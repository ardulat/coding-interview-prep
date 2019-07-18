// https://leetcode.com/problems/binary-tree-right-side-view/

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
    Retrieve all the last (rightmost) nodes in the level-order traversal
    */
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> current, next;
        if (root != NULL)
            current.push(root);
        vector<int> res;
        while (!current.empty()) {
            TreeNode *temp = current.front();
            current.pop();
            if (temp->left != NULL)
                next.push(temp->left);
            if (temp->right != NULL)
                next.push(temp->right);
            // if level has ended
            if (current.empty()) {
                res.push_back(temp->val); // <- was the rightmost/last node
                current.swap(next);
            }
        }
        return res;
    }
};