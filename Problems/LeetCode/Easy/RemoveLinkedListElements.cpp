// https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *iterator = head, *predHead = new ListNode(0), *pred = predHead;
        predHead->next = head;
        while (iterator != NULL) {
            if (iterator->val == val)
                pred->next = iterator->next;
            else
                pred = iterator;
            iterator = iterator->next;
        }
        return predHead->next;
    }
};