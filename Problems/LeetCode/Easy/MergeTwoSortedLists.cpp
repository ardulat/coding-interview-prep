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

// Solution 2:

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
        // take care of basic edge cases
        // case 1: l1 == NULL
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *iter1 = l1, *iter2 = l2; // two pointers
        ListNode *head = iter1; // copy pointer to iter1
        if (iter2->val < iter1->val) {
            head = iter2;
            iter2 = iter2->next;
        } else
            iter1 = iter1->next;
        ListNode* temp = head;
        // 1->2->4, 1->3->4
        while (iter1 != NULL && iter2 != NULL) {
            if (iter1->val < iter2->val) { // iter1->val is less
                temp->next = iter1;
                iter1 = iter1->next;
            } else {
                temp->next = iter2;
                iter2 = iter2->next;
            }
            temp = temp->next;
        }
        
        while (iter1 != NULL) {
            temp->next = iter1;
            iter1 = iter1->next;
            temp = temp->next;
        }
        
        while (iter2 != NULL) {
            temp->next = iter2;
            iter2 = iter2->next;
            temp = temp->next;
        }
        
        return head;
    }
};
