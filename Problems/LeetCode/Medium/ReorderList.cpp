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


// NOTE: The code is not that well-written
class Solution {
public:
    /*
    Algorithm 3: O(N) time, O(1) space
    - reverse the right half of the list
    - concatenate according to the order required using two pointers
    */
    ListNode* reverse(ListNode *head) {
        ListNode *left = NULL, *right = head;
        while (right != NULL) {
            ListNode *temp = right->next; // NULL
            right->next = left; // 4 -> 3
            left = right; // left = 4
            right = temp; // right = NULL
        }
        return left;
    }
    
    void reorderList(ListNode* head) {
        // handling base cases
        if (head == NULL || head->next == NULL)
            return;
        // let's use the Floyd's algorithm to find the half
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // separate both parts
        ListNode *temp = head;
        while (temp != NULL && temp->next != slow)
            temp = temp->next;
        if (temp != NULL)
            temp->next = NULL;
        ListNode *right = reverse(slow);
        ListNode *left = head;
        while (left != NULL && right != NULL) {
            ListNode *tempLeft = left->next; // 3
            ListNode *tempRight = right->next; // NULL
            left->next = right; // 2 -> 3
            if (tempLeft != NULL)
                right->next = tempLeft; // 3 -> NULL
            left = tempLeft; // 3
            right = tempRight; // NULL
        }
    }
};