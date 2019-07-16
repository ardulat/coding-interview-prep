// https://leetcode.com/problems/swap-nodes-in-pairs/

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
    ListNode* swapPairs(ListNode* head) {
        // base case:
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *tempHead = new ListNode(0);
        ListNode *temp = tempHead;
        ListNode *iterator = head;
        while (iterator != NULL && iterator->next != NULL) {
            ListNode *swapNext = iterator->next->next;
            temp->next = iterator->next;
            iterator->next->next = iterator;
            iterator->next = swapNext;

            iterator = iterator->next; // iterate
            temp = temp->next->next;
        }
        return tempHead->next;
    }
};