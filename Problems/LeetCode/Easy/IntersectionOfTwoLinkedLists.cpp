// https://leetcode.com/problems/intersection-of-two-linked-lists/

class Solution {
public:
    /*
    - find size of two lists
    - skip the first (sizeB-sizeA) nodes of the bigger list
    - start comparing and incrementing concurrently
    - if reached the end, no intersection (return NULL)
    */
    int size(ListNode *head) {
        int count = 0;
        while (head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = size(headA), sizeB = size(headB);
        int count = 0;
        ListNode *tempA = headA, *tempB = headB;
        // list A is asssumed to be bigger
        if (sizeA < sizeB)
            swap(tempA, tempB);
        while (count < abs(sizeA-sizeB)) {
            tempA = tempA->next;
            count++;
        }
        while (tempA != NULL && tempB != NULL) { // simultaneously
            if (tempA == tempB)
                return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }
};
