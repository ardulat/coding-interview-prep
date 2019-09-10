// https://leetcode.com/problems/rotate-list/

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
    int size(ListNode *head) {
        int count = 0;
        
        while (head != NULL) {
            count++;
            head = head->next;
        }
        
        return count;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL)
            return NULL;
        
        int n = size(head);
        int count = 1;
        ListNode *temp = head;
        
        k = k % n;
        if (k == 0)
            return head;
        
        while (count < n-k) {
            temp = temp->next;
            count++;
        }
        
        ListNode *newHead = temp->next;
        temp->next = NULL;
        temp = newHead;
        
        while (temp->next != NULL)
            temp = temp->next;
        
        temp->next = head;
        
        return newHead;
    }
};