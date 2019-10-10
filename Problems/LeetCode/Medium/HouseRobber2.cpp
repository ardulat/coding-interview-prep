// https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        else if (n == 1)
            return nums[0];
        
        vector<int> dp(n+1, 0); // memoization
        dp[0] = 0;
        dp[1] = nums[0];
        
        for (int i = 1; i < n-1; i++) {
            int val = nums[i];
            
            int rob = dp[i-1] + val;
            int notrob = dp[i];
            
            dp[i+1] = max(rob, notrob);
        }
        
        int first = dp[n-1];
        
        dp[1] = nums[1];
        
        for (int i = 2; i < n; i++) {
            int val = nums[i];
            
            int rob = dp[i-2] + val;
            int notrob = dp[i-1];
            
            dp[i] = max(rob, notrob);
        }
        
        int second = dp[n-1];
        
        return max(first, second);
    }
};