// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode *current, *next;
    current = A;
    next = A->next;
    
    while (current->next != NULL) {
        next = current->next;
        if (current->val == next->val)
            current->next = next->next;
        else {
            current = current->next;
        }
    }
    return A;
}
