// https://leetcode.com/problems/palindrome-linked-list/

// Approach: 1) get the middle pointer
//           2) reverse right half (starting from mid)
//           3) compare left and right half

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        // base case:
        if (head == NULL)
            return true;
        if (head->next == NULL)
            return true;
        
        // get middle node
        ListNode* mid = head, *prev;
        ListNode* fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            // prev = mid;
            fast = fast->next->next;
            mid = mid->next;
        }
        
        // reverse starting from mid
        ListNode* temp = mid->next;
        prev = NULL;
        
        while (temp != NULL) {
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        mid->next = prev;
        
        // compare left and right half
        ListNode *left = head, *right = mid->next;
        while (left != mid->next && right != NULL) {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        
        return true;
    }
};