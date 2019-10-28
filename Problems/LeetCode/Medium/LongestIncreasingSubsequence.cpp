// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
private:
    vector<int> dp; // max length from current index
    
public:
    /*
    Brute-force: O(N^2)
    - run O(N) algorithm from each i in array
    - modify linear algorithm for subsequence (non-continuous)
    - dynamic programming for repeating calls
    
    [10,9,2,5,3,4]
    */
    int lengthOfLIS(vector<int>& nums, int roi, int start) {
        int n = nums.size();
        if (start >= n)
            return 0;
        
        if (dp[start] != -1)
            return dp[start];
        
        int maxLen = 0, currentMax = 0;
        
        for (int i = start; i < n; i++) {
            if (roi < nums[i]) {
                currentMax += lengthOfLIS(nums, nums[i], i+1) + 1;
                
                maxLen = max(maxLen, currentMax);
                currentMax = 0;
            }
        }
        
        dp[start] = maxLen;
        
        return maxLen;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        this->dp = vector<int>(nums.size(), -1);
        
        return lengthOfLIS(nums, INT_MIN, 0);
    }
};

// DP iterative
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0)
            return 0;
        
        int maxLen = 1, currentMax;
        vector<int> dp(n, -1); // max len starting from index i
        dp[0] = 1;
        
        for (int i = 1; i < n; i++) {
            currentMax = 0;
            
            for (int j = i-1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    currentMax = max(currentMax, dp[j]); // append to seq
                }
                // otherwise, do not append to seq
            }
            
            dp[i] = currentMax+1; // prev seq + itself
            maxLen = max(maxLen, dp[i]);
        }
        
        return maxLen;
    }
};
