// https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                count++;
            if (nums[i] == 0 || i == nums.size()-1) {
                // stop counting and update values
                maxCount = max(maxCount, count);
                count = 0;
                continue;
            }
        }
        // maxCount = max(maxCount, count);
        return maxCount;
    }
};