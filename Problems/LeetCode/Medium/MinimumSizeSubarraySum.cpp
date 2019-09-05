// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, right;
        int sum = 0;
        int minLen = INT_MAX;
        
        if (s == 0 || nums.empty())
            return 0;
        
        sum += nums[left]; // initially
        right = left;
        
        while (right < nums.size()) {
            if (sum >= s) {
                minLen = min(right-left+1, minLen);
                sum -= nums[left];
                left++;
            }
            else {
                right++;
                if (right == nums.size()) break;
                sum += nums[right];
            }
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
};