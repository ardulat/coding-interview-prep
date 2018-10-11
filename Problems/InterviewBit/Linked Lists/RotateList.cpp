// https://www.interviewbit.com/problems/rotate-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int length(ListNode* A) {
    int count = 0;
    while (A != NULL) {
        A = A->next;
        count++;
    }
    return count;
}
ListNode* Solution::rotateRight(ListNode* A, int B) {
    
    int n = length(A), count = 0;
    int k = B % n;
    ListNode *newHead, *newTail;
    newHead = A;
    
    if (k == 0)
        return A;
    
    while (count < n-k) {
        newTail = newHead;
        newHead = newHead->next;
        count++;
    }
    
    // connect
    ListNode* temp = newHead;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = A;
    A = newHead;
    newTail->next = NULL;
    
    return A;
}
