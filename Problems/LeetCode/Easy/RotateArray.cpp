// https://leetcode.com/problems/rotate-array/

class Solution {
public:
    /*
    [1,2,3,4,5,6,7]
    [1,2,3,4,5,6,7,8] -> 3 steps: [6,7,8,1,2,3,4,5]
    */
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> shift(k,0);
        
        for (int i = n-k; i < n; i++)
            shift[i-(n-k)] = nums[i]; // copy the last k elements
        
        for (int i = n-1; i >= k; i--)
            nums[i] = nums[i-k]; // copy the first n-k elements to the end
        
        for (int i = 0; i < k; i++)
            nums[i] = shift[i]; // copy the shifted elements from extra array
    }
};