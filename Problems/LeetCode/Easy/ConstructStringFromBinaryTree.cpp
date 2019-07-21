// https://leetcode.com/problems/construct-string-from-binary-tree/

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
    string tree2str(TreeNode* t) {
        string res = "";
        if (t == NULL) return res;
        res += to_string(t->val);
        string left = tree2str(t->left);
        string right = tree2str(t->right);
        if (!left.empty()) res += '('+left+')';
        if (!right.empty()) {
            if (left.empty()) res += "()";
            res += '('+right+')';
        }
        return res;
    }
};