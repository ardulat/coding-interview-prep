// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

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
        Node *temp = root;
        
        while (temp != NULL) {
            Node *nextHead = new Node(0, NULL, NULL, NULL); // head of next level
            Node *nextTemp = nextHead; // temp of next level
            
            while (temp != NULL) {
                // cout << "checkpoint: " << temp->val << endl;
                if (temp->left != NULL) {
                    nextTemp->next = temp->left;
                    nextTemp = nextTemp->next;
                }
                if (temp->right != NULL) {
                    nextTemp->next = temp->right;
                    nextTemp = nextTemp->next;
                }
                temp = temp->next;
            }
            
            temp = nextHead->next;
        }
        
        return root;
    }
};