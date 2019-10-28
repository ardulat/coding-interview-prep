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