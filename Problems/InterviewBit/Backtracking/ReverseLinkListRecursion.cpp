// https://www.interviewbit.com/problems/reverse-link-list-recursion/

void reverse(ListNode* p, ListNode* &A) {
    
    if (p->next == NULL) {
        A = p;
        return;
    }
    reverse(p->next, A);
    p->next->next = p;
    p->next = NULL;
}

ListNode* Solution::reverseList(ListNode* A) {
    reverse(A, A);
    return A;
}
