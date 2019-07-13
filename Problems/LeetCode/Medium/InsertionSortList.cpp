// https://leetcode.com/problems/insertion-sort-list/

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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *sorted = new ListNode(0);
        ListNode *red = head;
        while (red != NULL) {
            ListNode *black = sorted;
            while (black->next != NULL && black->next->val < red->val)
                black = black->next;
            ListNode *rest_sorted = black->next;
            ListNode *rest_unsorted = red->next;
            black->next = red;
            red->next = rest_sorted;
            red = rest_unsorted;
        }
        return sorted->next;
    }
};