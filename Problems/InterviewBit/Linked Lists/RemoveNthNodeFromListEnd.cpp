// https://www.interviewbit.com/problems/remove-nth-node-from-list-end/

int length(ListNode* A) {
    int count = 0;
    while (A != NULL) {
        A = A->next;
        count++;
    }
    return count;
}

ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    
    int n = length(A);
    if (B >= n) {
        // remove first
        A = A->next;
        return A;
    }
    
    int m = n-B;
    int count = 0;
    ListNode* temp = A;
    while (count < m-1) {
        temp = temp->next;
        count++;
    }
    // remove Nth
    temp->next = temp->next->next;
    
    return A;
}
