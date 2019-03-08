// https://leetcode.com/problems/merge-two-sorted-lists/submissions/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode *head, *prev;
        
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        
        if (l1->val <= l2->val) {
            head = l1;
            prev = l1;
            l1 = l1->next;
        } else {
            head = l2;
            prev = l2;
            l2 = l2->next;
        }
            
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                prev->next = l1;
                prev = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                prev = l2;
                l2 = l2->next;
            }
        }
        if (l1 == NULL)
            prev->next = l2;
        if (l2 == NULL)
            prev->next = l1;
        
        return head;
    }
};