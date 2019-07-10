// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *left = head, *right = head;
        int steps = 0;
        while (steps < n) {
            right = right->next;
            steps++;
        }
        if (right == NULL)
            return head->next;
        while (right->next != NULL) {
            left = left->next;
            right = right->next;
        }
        if (left->next != NULL)
            left->next = left->next->next;
        return head;
    }
};