// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        
        Node *prev = head, *next = prev->next;
        
        // step 1: interveave list
        do {
            Node *temp = new Node (prev->val, next, NULL); // link temp to next
            prev->next = temp; // link prev to temp
            
            prev = next;
            if (next != NULL)
                next = next->next;
        } while (prev != NULL);
        
        // step 2: copy random references
        Node *temp = head, *copy = head->next;
        do {
            if (temp->random != NULL)
                copy->random = temp->random->next;
            temp = copy->next;
            if (temp != NULL)
                copy = temp->next;
        } while (temp != NULL);
        
        // step 3: remove original nodes, return the original list back
        Node *newHead = head->next;
        temp = newHead;
        Node *original = head;
        // head->next = original; // original
        while (temp->next != NULL) {
            original->next = temp->next;
            original = original->next;
            
            next = temp->next->next; // third node
            temp->next = next;
            temp = next;
        }
        
        original->next = NULL;
        
        return newHead;
    }
};