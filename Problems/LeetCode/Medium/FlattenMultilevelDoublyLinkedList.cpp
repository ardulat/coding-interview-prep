// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node *temp = head;
        
        while (temp != NULL && temp->child == NULL)
            temp = temp->next;
        
        if (temp == NULL) // there are no children
            return head;
        
        Node *children = flatten(temp->child); // recursively flattened children
        temp->child = NULL; // remove children's link
        Node *next = temp->next;
        
        // link previous node with children's head
        temp->next = children;
        children->prev = temp;
        
        if (next == NULL)
            return head;
        
        // get the last node of nested (child) list
        while (children->next != NULL)
            children = children->next;
        
        // link next node with children's tail
        children->next = next;
        next->prev = children;
        
        next = flatten(next); // flatten the rest
        
        return head;
    }
};