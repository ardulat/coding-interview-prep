// https://www.interviewbit.com/problems/merge-two-sorted-lists/

ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *i = A, *j = B, *newHead = NULL;
    ListNode *temp;
    
    while (i != NULL && j != NULL) {
        // cout << "i: "<<i->val << " j: "<<j->val << endl;
        if (i->val < j->val) {
            if (newHead == NULL)
                newHead = temp = A;
            else {
                temp->next = i;
                temp = i;
            }
            i = i->next;
        }
        else {
            if (newHead == NULL)
                newHead = temp = B;
            else {
                temp->next = j;
                temp = j;
            }
            j = j->next;
        }
    }
    
    while (i != NULL) {
        temp->next = i;
        temp = i;
        i = i->next;
    }
    while (j != NULL) {
        temp->next = j;
        temp = j;
        j = j->next;
    }
    return newHead;
}
