// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int overallMax = nums[0], currentMax = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            currentMax += nums[i];
            overallMax = max(overallMax, currentMax);
            // start from the beginning
            currentMax = max(currentMax, 0);
        }
        
        return overallMax;
    }
};