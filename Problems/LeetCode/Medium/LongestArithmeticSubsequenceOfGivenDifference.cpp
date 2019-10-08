// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

class Solution {
public:
    /*
    Brute-force: TLE O(N^2)
    - start of with one for loop that iterates over all elements considered as a start of the subsequence
        - in the inner loop add all numbers in subsequence if equal to difference
    - estimate its length, if greater -> update
    
    Optimization: DP O(N)
    - memoize longest length of subsequence ending at arr[i] element by index
    */
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        int maxLen = 0;
        unordered_map<int,int> dp;
        dp[arr[n-1]] = 1;
        
        for (int i = n-2; i >= 0; i--) {
            int num = arr[i];
            dp[num] = dp[num+difference] + 1;
            
            maxLen = max(maxLen, dp[num]);
        }
        
        return maxLen;
    }
};