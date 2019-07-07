// https://leetcode.com/problems/next-greater-node-in-linked-list/

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        ListNode *cur = head;
        while (cur != NULL) {
            ListNode *greater = cur->next;
            while (greater != NULL && greater->val <= cur->val)
                greater = greater->next;
            if (greater == NULL)
                res.push_back(0);
            else
                res.push_back(greater->val);
            cur = cur->next;
        }
        return res;
    }
};

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        while (head != NULL) {
            res.push_back(head->val);
            head = head->next;
        }
        stack<int> st;
        for (int i = res.size()-1; i >= 0; i--) {
            int val = res[i];
            while (!st.empty() && st.top() <= val)
                st.pop();
            res[i] = st.empty() ? 0 : st.top();
            st.push(val);
        }
        return res;
    }
};