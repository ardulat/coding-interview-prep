// https://www.interviewbit.com/problems/partition-list/

// NOTE: think out of the box, do not stick to quicksort's partition in this case.

ListNode* Solution::partition(ListNode* A, int B) {
    // initalize 2 pointers for two lists (smaller, greater or equal)
    ListNode *smallerHead = NULL, *smallerTail = NULL;
    ListNode *greaterHead = NULL, *greaterTail = NULL;
    
    // iterate through list
    ListNode* current = A;
    while (current) {
        // if current is less than B, then add to smaller list
        if (current->val < B) {
            if (smallerHead == NULL) // for the first time
                smallerHead = current;
            else
                smallerTail->next = current;
            smallerTail = current;
        }
        // if current is greater or equal to B, then add to greater or equal list
        else {
            if (greaterHead == NULL) // for the first time
                greaterHead = current;
            else
                greaterTail->next = current;
            greaterTail = current;
        }
        // iterate
        current = current->next;
    }
    
    // put NULL at the end of greaterTail to avoid cycle coming from past list
    greaterTail->next = NULL;
    
    // concatenate two lists
    if (smallerHead == NULL)
        return greaterHead;
    else {
        smallerTail->next = greaterHead;
        return smallerHead;
    }
}
