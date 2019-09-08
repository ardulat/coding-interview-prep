// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != 0) {
                swap(nums[count], nums[i]);
                count++;
            }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1)
            return;
        
        int idx = 0;
        
        for (int i = 0; i < n; i++)
            if (nums[i] != 0) {
                swap(nums[i], nums[idx]);
                idx++;
            }
        // fill the rest with zeroes
        while (idx < n) {
            nums[idx] = 0;
            idx++;
        }
    }
};