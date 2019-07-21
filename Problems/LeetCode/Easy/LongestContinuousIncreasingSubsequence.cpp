// https://leetcode.com/problems/longest-continuous-increasing-subsequence/

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int max_so_far = 1, current_max = 1;
        for (int i = 0; i < (int) nums.size()-1; i++) {
            if (nums[i] < nums[i+1]) current_max++;
            else {
                max_so_far = max(max_so_far, current_max);
                current_max = 1;
            };
        }
        return nums.empty() ? 0 : max(max_so_far, current_max);
    }
};