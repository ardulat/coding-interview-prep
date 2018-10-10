// https://www.interviewbit.com/problems/list-cycle/

// hint: Floyd's Cycle-Finding Algorithm
// futher knowledge: https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/

ListNode* Solution::detectCycle(ListNode* A) {
    ListNode *slow, *fast;
    slow = A;
    fast = A;
    
    // determine if there is a loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    
    // if loop exists
    if (slow == fast) {
        slow = A;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    
    return NULL;
}
