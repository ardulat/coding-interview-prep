// https://leetcode.com/problems/reverse-linked-list/

// Iterative: faster, simpler
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *current;
        current = head;
        
        // base case:
        if (head == NULL)
            return NULL;
        
        while (current != NULL) { // will go till the last element
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        head = prev;
        
        return head;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;
        
        ListNode *temp = head;
        ListNode *next;
        
        while (temp->next != NULL) {
            next = temp->next;
            temp->next = next->next; // setting current next to next's next
            next->next = head; // reverse step
            head = next; // update head to new one
        }
        
        return head; // return last next
    }
};

// Recursive: slower
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* first = head;
        // base case 1:
        if (first == NULL)
            return head;
        ListNode* rest = head->next;
        // base case 2:
        if (rest == NULL)
            return head;
        rest = reverseList(rest);
        head = rest;
        // go to the end of the rest list
        while (rest->next != NULL)
            rest = rest->next;
        rest->next = first;
        first->next = NULL;
        
        return head;
    }
};