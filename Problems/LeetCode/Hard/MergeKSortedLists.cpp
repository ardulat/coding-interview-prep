// https://leetcode.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct comparator {
    bool operator() (const ListNode* l, const ListNode* r) { 
        return l->val > r->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< ListNode*, vector< ListNode* >, comparator> pq;
        
        for (ListNode* head : lists) {
            if (head != NULL)
                pq.push(head);
        }
        
        if (pq.empty())
            return NULL;
        
        ListNode* result = pq.top();
        pq.pop();
        ListNode* temp = result;
        if (temp->next)
            pq.push(temp->next);
        
        while (!pq.empty()) {
            temp->next = pq.top();
            pq.pop();
            if (temp->next->next != NULL)
                pq.push(temp->next->next);
            temp = temp->next;
        }
        
        return result;
    }
};