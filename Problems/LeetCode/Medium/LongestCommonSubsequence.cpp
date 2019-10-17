// https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (text1[i-1] == text2[j-1]) {
                    // common character
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[len1][len2];
    }
};