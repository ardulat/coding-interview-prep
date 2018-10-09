// https://www.interviewbit.com/problems/swap-list-nodes-in-pairs/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    ListNode *current, *prev, *next;
    current = A;
    
    while (current != NULL && current->next != NULL) {
        next = current->next;
        // swap
        current->next = next->next;
        next->next = current;
        
        if (A == current)
            A = next;
        
        if (prev != NULL)
            prev->next = next;
        prev = current;
        // iterate
        current = current->next;
    }
    return A;
}
