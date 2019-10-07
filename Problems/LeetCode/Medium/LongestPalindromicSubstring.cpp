// https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        string res = "";
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            res = s[i];
        }
        
        for (int i = 0; i < n-1; i++)
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                res = s.substr(i, 2);
            }
        
        int maxLen = 0;
        
        for (int i = n-1; i >= 0; i--)
            for (int d = 2; d < n-i; d++) {
                int left = i;
                int right = i+d;
                
                dp[left][right] = dp[left+1][right-1] && s[left] == s[right];
                
                if (dp[left][right] && right-left+1 > maxLen) {
                    maxLen = right-left+1;
                    res = s.substr(left, maxLen);
                }
            }
        
        return res;
    }
};