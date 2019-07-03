// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode*> nodes;
        nodes.push(root);
        for (int i = 1; i < preorder.size(); i++) {
            TreeNode *temp = new TreeNode(preorder[i]);
            if (temp->val < nodes.top()->val)
                nodes.top()->left = temp;
            else {
                TreeNode *prev;
                while (!nodes.empty() && nodes.top()->val < temp->val) {
                    prev = nodes.top();
                    nodes.pop();
                }
                prev->right = temp;
            }
            nodes.push(temp);
        }
        return root;
    }
};