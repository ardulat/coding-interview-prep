// https://leetcode.com/problems/symmetric-tree/

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
    bool validate(deque<TreeNode*> next) {
        while (!next.empty()) {
            TreeNode *left = next.front(), *right = next.back();
            next.pop_front();
            next.pop_back();
            if (left == NULL && right == NULL)
                continue;
            else if (left != NULL && right != NULL) {
                if (left->val != right->val)
                    return false;
            }
            else
                return false;
        }
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        // level order traversal
        deque<TreeNode*> level, next;
        level.push_back(root);
        while (!level.empty()) {
            TreeNode *temp = level.front();
            level.pop_front();
            if (temp != NULL)
                next.push_back(temp->left);
            if (temp != NULL)
            next.push_back(temp->right);
            if (level.empty()) {
                // validate next level
                if(!validate(next))
                    return false;
                swap(level, next);
            }
        }
        return true;
    }
};