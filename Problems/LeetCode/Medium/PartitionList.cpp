// https://leetcode.com/problems/partition-list/

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
    /*
    Algorithm 1 (easy solution): O(N) time, O(N) space
    - store nodes less than X, and greater than or equal to X in separate arrays
    - reorder the list according to the order in the arrays
    */
    ListNode* partition(ListNode* head, int x) {
        vector<ListNode*> left, right;
        ListNode *temp = head;
        while (temp != NULL) {
            if (temp->val < x)
                left.push_back(temp);
            else
                right.push_back(temp);
            temp = temp->next;
        }
        if (left.empty() || right.empty())
            return head;
        head = left[0];
        for (int i = 1; i < left.size(); i++)
            left[i-1]->next = left[i];
        for (int i = 1; i < right.size(); i++)
            right[i-1]->next = right[i];
        left[left.size()-1]->next = right[0];
        right[right.size()-1]->next = NULL;
        return head;
    }
};


class Solution {
public:
    /*
    Algorithm 2: O(N) time, O(1) space
    - traverse the array with two pointers
    - reorder according to the first occurence of less than and greater or equal
    */
    ListNode* partition(ListNode* head, int x) {
        // base cases
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *leftHead = new ListNode(0), *rightHead = new ListNode(0);
        ListNode *left = leftHead, *right = rightHead;
        while (head != NULL) {
            if (head->val < x) {
                left->next = head;
                left = left->next;
            } else {
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }
        right->next = NULL;
        left->next = rightHead->next;
        return leftHead->next;
    }
};
