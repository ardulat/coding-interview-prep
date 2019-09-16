// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    inorder = [2,1,3]
    postorder = [2,3,1]
    
    - last node in postorder is ROOT
    - left subtree is left to the ROOT in inorder
    - right subtree is right to the ROOT in inorder
    - from left and right inorders construct postorder in postorder
    - recursively pass inorder and postorder
    - connect subtrees
    */
    TreeNode* buildTree(vector<int>& inorder, int istart, int iend,
                        vector<int>& postorder, int pstart, int pend,
                        unordered_map<int,int>& nodes) {
        // base case
        if (istart > iend || pstart > pend)
            return NULL;
        
        int val = postorder[pend]; // root value
        int pos = nodes[val]; // position of the root
        TreeNode *root = new TreeNode(val);
        /*
        inorder = [9,3,15,20,7]
        postorder = [9,15,7,20,3]
        
        pos = 1
        iend = 4
        pend = 3
        
        iend-pos = 3
        pos-istart = 1-0 = 1
        
        pstart+(pos-istart)-1
        pend-(iend-pos)+1
        */
        // recur
        TreeNode *left = buildTree(inorder, istart, pos-1,
                                   postorder, pstart, pstart+(pos-istart)-1,
                                   nodes);
        TreeNode *right = buildTree(inorder, pos+1, iend,
                                    postorder, pend-(iend-pos), pend-1,
                                    nodes);
        
        root->left = left;
        root->right = right;
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // construct hashmap
        unordered_map<int,int> nodes;
        for (int i = 0; i < inorder.size(); i++)
            nodes[inorder[i]] = i;
        
        return buildTree(inorder, 0, inorder.size()-1,
                         postorder, 0, postorder.size()-1,
                         nodes);
    }
};