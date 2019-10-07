// https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    /*
    DP:
    - navigate through pairs of [left, right] substrings as two-dimensional array
    - three conditions:
        - left == right: dp[left][right] = true
        - left > right: dp[left][right] = false
        - left < right:
            1) s[left] == s[right] -> dp[left][right] = dp[left+1][right-1]
            2) s[left] != s[right] -> d[left][right] = false
    */
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false)); // dp[n][n]
        
        // step 1: start of by adding (left == right) as palindromes
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        
        // step 2: continue by adding palindromes of size 2 or more
        for (int i = 0; i < n-1; i++)
            if (s[i] == s[i+1])
                dp[i][i+1] = true;
        
        // step 3: try all pairs O(N^2) of size 3 or more
        for (int i = n-1; i >= 0; i--)
            for (int dist = 2; dist < n-i; dist++) {
                int left = i;
                int right = left + dist;
                if (s[left] == s[right])
                    dp[left][right] = dp[left+1][right-1];
                else
                    dp[left][right] = false;
            }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // cout << dp[i][j] << " ";
                if (dp[i][j])
                    count++;
            }
            // cout << endl;
        }
        
        return count;
    }
};