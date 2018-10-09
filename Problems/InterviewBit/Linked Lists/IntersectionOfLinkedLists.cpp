// https://www.interviewbit.com/problems/intersection-of-linked-lists/


// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

int length(ListNode* A) {
    int count = 0;
    while (A != NULL) {
        A = A->next;
        count++;
    }
    return count;
}

ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    
    int n = length(A);
    int m = length(B);
    int d = n-m; // assume: first list is bigger
    
    if (m > n) {
        d = -d;
        // swap lists:
        ListNode* temp = A;
        A = B;
        B = temp;
    }
    
    // walk the difference
    for (int i = 0; i < d; i++)
        A = A->next;
        
    // both should have the same length now
    while (A != NULL) { // no need of B != NULL
        if (A == B)
            return A;
        A = A->next;
        B = B->next;
    }
    return NULL; // no merge point
}
