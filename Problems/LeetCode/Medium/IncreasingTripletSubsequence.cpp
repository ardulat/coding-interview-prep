// https://leetcode.com/problems/increasing-triplet-subsequence/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int first = INT_MAX, second = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums[i] < first) first = nums[i];
            if (nums[i] > first) second = min(second, nums[i]);
            if (nums[i] > second) return true;
        }
        return false;
    }
};