// https://leetcode.com/problems/missing-number/

// Approach 1: use math
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // determine n and total sum
        int n = nums.size();
        int total = n*(n+1)/2;
        
        // subtract all numbers present
        for (int num : nums) {
            total = total-num;
        }
        
        return total;
    }
};

// Approach 2: use XOR
// Note: revise binary operations!
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_true = 1;
        for (int i = 2; i <= n; i++)
            xor_true = xor_true^i;
        int xor_actual = nums[0];
        for (int i = 1; i < n; i++)
            xor_actual = xor_actual^nums[i];
        
        return xor_actual^xor_true;
    }
};