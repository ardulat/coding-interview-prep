// https://leetcode.com/problems/total-hamming-distance/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for (int i = 0; i < 31; i++) {
            int setBits = 0;
            for (int j = 0; j < n; j++) {
                setBits += nums[j] & 1;
                nums[j] = nums[j] >> 1;
            }
            total += setBits * (n-setBits);
        }
        return total;
    }
};