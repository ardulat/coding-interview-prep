// https://leetcode.com/problems/reorder-list/

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
    Algorithm 1: O(N) time, O(N) space
    - store all the nodes in a vector of ListNode*
    - reorder the list by refering to the values of type ListNode* in a vector
    
    Algorithm 2: O(N^2) time, O(1) space
    - count the size of array
    - start a counter and everytime traverse the list until reaching the node
    
    Algorithm 3: O(N) time, O(1) space
    - reverse the right half of the list
    - concatenate according to the order required
    */
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;
        ListNode *temp = head;
        while (temp != NULL) {
            nodes.push_back(temp);
            temp = temp->next;
        }
        int left = 0, right = nodes.size()-1;
        while (left <= right) {
            temp = nodes[left]->next;
            nodes[left]->next = nodes[right];
            nodes[right]->next = temp;
            left++;
            right--;
        }
        if (!nodes.empty())
            nodes[++right]->next = NULL;
    }
};


