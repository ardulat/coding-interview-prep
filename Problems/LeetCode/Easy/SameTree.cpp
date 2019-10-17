// https://leetcode.com/problems/same-tree/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        if (p != NULL && q != NULL && p->val == q->val)
            return isSameTree(p->left, q->left) & isSameTree(p->right, q->right);
        return false;
    }
};

// Iterative approach

typedef pair<TreeNode*, TreeNode*> pr;

class Solution {
public:
    bool check (TreeNode *first, TreeNode *second) {
        if (first == NULL && second == NULL)
            return true;
        if (first == NULL || second == NULL)
            return false;
        
        if (first->val != second->val)
            return false;
        
        return true;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pr> nodes;
        nodes.push({p, q});
        
        while (!nodes.empty()) {
            pr p = nodes.front();
            nodes.pop();
            
            TreeNode *first = p.first;
            TreeNode *second = p.second;
            
            if (!check(first, second))
                return false;
            
            if (first != NULL && second != NULL) {
                nodes.push({first->left, second->left}); // lefts pair
                nodes.push({first->right, second->right}); // rights pair
            }
        }
        
        return true;
    }
};
