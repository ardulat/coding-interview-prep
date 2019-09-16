// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* buildTree(vector<int>& preorder, int pstart, int pend,
                        vector<int>& inorder, int istart, int iend,
                        unordered_map<int,int>& nodes) {
        if (pstart > pend || istart > iend)
            return NULL;
        
        int val = preorder[pstart]; // root value
        int pos = nodes[val]; // root position
        TreeNode *root = new TreeNode(val);
        // (pos-istart) = number of left nodes
        TreeNode *left = buildTree(preorder, pstart+1, pstart+(pos-istart),
                                   inorder, istart, pos-1,
                                   nodes);
        // (iend-pos) = number of right nodes
        TreeNode *right = buildTree(preorder, pend-(iend-pos-1), pend,
                                    inorder, pos+1, iend,
                                    nodes);
        
        root->left = left;
        root->right = right;
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> nodes;
        
        for (int i = 0; i < inorder.size(); i++)
            nodes[inorder[i]] = i;
        
        return buildTree(preorder, 0, preorder.size()-1,
                         inorder, 0, inorder.size()-1,
                         nodes);
    }
};