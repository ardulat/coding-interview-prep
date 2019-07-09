// https://leetcode.com/problems/add-two-numbers-ii/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        while (l1 != NULL) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            st2.push(l2->val);
            l2 = l2->next;
        }
        stack<int> res;
        int carry = 0;
        while (!st1.empty() || !st2.empty()) {
            int num1 = 0, num2 = 0;
            if (!st1.empty()) {
                num1 = st1.top();
                st1.pop();
            }
            if (!st2.empty()) {
                num2 = st2.top();
                st2.pop();
            }
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            res.push(sum);
        }
        if (carry != 0)
            res.push(carry);
        ListNode *sumHead = new ListNode(0);
        ListNode *temp = sumHead;
        while (!res.empty()) {
            temp->next = new ListNode(res.top());
            res.pop();
            temp = temp->next;
        }
        return sumHead->next;
    }
};