// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    /*
    - make us of sorted property
    */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;
        while (temp != NULL && temp->next != NULL) {
            if (temp->next->val == temp->val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        return head;
    }
};