// https://leetcode.com/problems/house-robber/submissions/

class Solution {
public:
    /*
    Brute-force: TLE
    
    Optimization:
    - store max sums in array (dp memoization)
    
    */
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int n = nums.size();
        vector<int> dp(n+1, 0); // n+1 for the last+1
        dp[0] = 0;
        dp[1] = nums[0];
        
        for (int i = 1; i < n; i++) {
            int val = nums[i];
            
            int rob = dp[i-1]+val;
            int notrob = dp[i];
            
            dp[i+1] = max(rob, notrob);
        }
        
        return dp[n];
    }
};