// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

// Approach: max-heap (priority_queue in STL)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for (int i = 0; i < nums.size(); i++)
            pq.push(nums[i]);
        
        int temp;
        for (int i = 0; i < k; i++) {
            temp = pq.top();
            pq.pop();
        }
        
        return temp;
    }
};