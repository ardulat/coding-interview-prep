// https://www.interviewbit.com/problems/reverse-link-list-ii/

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if (B == C)
        return A;
    ListNode *current, *prev, *next;
    ListNode *prevMNode = NULL, *mNode, *nNode, *nextNNode;
    
    current = A;
    mNode = A;
    nNode = A;
    // reach M
    int count = 1;
    while (count < B) {
        prevMNode = mNode;
        mNode = mNode->next;
        count++;
    }
    // reach N
    count = 1;
    while (count < C) {
        nNode = nNode->next;
        count++;
    }
    nextNNode = nNode->next;
    
    // reverse
    prev = mNode;
    current = mNode->next;
    
    while (current != nextNNode) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    // finish him
    mNode->next = nextNNode;
    if (prevMNode == NULL) {
        prevMNode = nNode;
        return prevMNode;
    }
    
    prevMNode->next = nNode;
    
    return A;
}
