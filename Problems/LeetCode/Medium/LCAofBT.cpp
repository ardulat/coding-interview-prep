// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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
    bool findPath(TreeNode* root, vector<TreeNode*> &path, TreeNode* node) {
        // base case:
        if (root == NULL)
            return false;
        path.push_back(root); // add it to the path first
        // check if current node is what we need
        if (root == node)
            return true;
        // check if it exists in either of subtrees
        if ((root->left != NULL && findPath(root->left, path, node))
           || (root->right != NULL && findPath(root->right, path, node)))
            return true;
        // else it is not present here
        path.pop_back();
        return false;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path2P, path2Q;
        
        findPath(root, path2P, p);
        findPath(root, path2Q, q);
        
        // check both pathes
        int i = 0;
        while (path2P[i+1] == path2Q[i+1] &&
               i+1 < path2P.size() && i+1 < path2Q.size()) {
            i++;
        }
        return path2P[i];
    }
};