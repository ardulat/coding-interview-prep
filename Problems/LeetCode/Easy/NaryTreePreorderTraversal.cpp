// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void preorder(Node *root, vector<int>& order) {
        if (root == NULL)
            return;
        
        order.push_back(root->val);
        
        for (Node *child : root->children)
            preorder(child, order);
    }
    
    vector<int> preorder(Node* root) {
        vector<int> res;
        
        preorder(root, res);
        
        return res;
    }
};