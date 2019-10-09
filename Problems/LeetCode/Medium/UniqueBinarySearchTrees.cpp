// https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
    /*
    Brute-force: TLE
    
    Optimization: DP
    */
    int numTrees(int start, int end, vector<vector<int>>& dp) {
        if (start > end)
            return 1;
        if (start == end)
            return 1;
        
        if (dp[start][end] > 0)
            return dp[start][end];
        
        int res = 0;
        
        for (int i = start; i <= end; i++) {
            // i-th root
            int lefts = numTrees(start, i-1, dp);
            int rights = numTrees(i+1, end, dp);
            
            res += lefts * rights;
        }
        
        // memoization
        dp[start][end] = res;
        
        return res;
    }
    
    int numTrees(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        return numTrees(1, n, dp);
    }
};