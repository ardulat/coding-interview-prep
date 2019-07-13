// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return root;
        root->left->next = root->right;
        if (root->next != NULL)
            root->right->next = root->next->left;
        root->left = connect(root->left);
        root->right = connect(root->right);
        
        return root;
    }
};