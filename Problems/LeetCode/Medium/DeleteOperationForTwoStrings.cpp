// https://leetcode.com/problems/delete-operation-for-two-strings/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        vector<vector<int>> dp (len1+1, vector<int>(len2+1, 0));
        
        for (int i = 0; i <= len1; i++)
            dp[i][0] = i;
        for (int j = 0; j <= len2; j++)
            dp[0][j] = j;
        
        for (int i = 1; i <= len1; i++)
            for (int j = 1; j <= len2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    // skip both characters
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    int removeFromFirst = dp[i][j-1]+1;
                    int removeFromSecond = dp[i-1][j]+1;
                    dp[i][j] = min(removeFromFirst, removeFromSecond);
                }
            }
        
        return dp[len1][len2];
    }
};