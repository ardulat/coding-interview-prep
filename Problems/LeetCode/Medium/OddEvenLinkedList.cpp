// https://leetcode.com/problems/odd-even-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // creepy base case
        if (head == NULL)
            return head;
        ListNode *headEven = head->next;
        ListNode *temp = head, *odd, *even;
        
        while (temp != NULL && temp->next != NULL) {
            odd = temp;
            even = temp->next;
            // cout << "odd: "<<odd->val<<", even: "<<even->val << endl;
            odd->next = even->next;
            if (even->next != NULL)
                even->next = odd->next->next;
            // iterate
            temp = temp->next;
        }
        
        if (temp == NULL)
            odd->next = headEven;
        else if (temp->next == NULL)
            temp->next = headEven;
        
        return head;
    }
};