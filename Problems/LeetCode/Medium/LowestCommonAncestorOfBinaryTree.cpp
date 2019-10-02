// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/

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
    bool findPath(TreeNode *root, TreeNode *node, vector<TreeNode*>& path) {
        if (root == NULL)
            return false;
        
        cout << root->val << endl;
        path.push_back(root);
        
        if (root == node)
            return true;
        
        if (findPath(root->left, node, path) ||
            findPath(root->right, node, path))
            return true;
        
        path.pop_back();
        
        return false;
    }
    
    TreeNode* CommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path2p, path2q; // path to p, path to q
        
        findPath(root, p, path2p);
        findPath(root, q, path2q);
        
        int i = 0;
        while (i+1 < path2p.size() &&
               i+1 < path2q.size() &&
               path2p[i+1] == path2q[i+1])
            i++;
        
        return path2p[i]; // or path2q[i]
    }
};