// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/s

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
    Algorithm 1: O(N) time, O(N) space
    - count and add numbers to hashtable
    - if count is more than 1, then don't add to new list
    
    Algorithm 2: O(N) time, O(1) space
    - maintain previous node
    - remove duplicate by changing the next of the previous node
    */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = NULL, *temp = head;
        
        while (temp != NULL && temp->next != NULL) {
            if (temp->val == temp->next->val) {
                while (temp->next != NULL && temp->val == temp->next->val)
                    temp->next = temp->next->next;
                if (prev != NULL) {
                    prev->next = temp->next;
                    temp = prev->next;
                } else {
                    head = temp->next;
                    temp = head;
                }
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};