// https://leetcode.com/problems/counting-bits/

class Solution {
public:
    /*
    0 = 0000 -> 0
    1 = 0001 -> 1
    2 = 0010 -> 1
    3 = 0011 -> 2
    4 = 0100 -> 1
    5 = 0101 -> 2
    6 = 0110 -> 2
    7 = 0111 -> 3
    8 = 1000 -> 1
    9 = 1001 -> 2
    10 = 1010 -> 2
    11 = 1011 -> 3
    12 = 1100 -> 2
    13 = 1101 -> 3
    14 = 1110 -> 3
    15 = 1111 -> 4
    
    iterative:
    - dp[0] = 0, dp[1] = 1
    - from 0,1 we construct 2-3: dp[2] = dp[0]+1, dp[3] = dp[1]+1
    - from 0-3 we construct 4-7: dp[4] = dp[0]+1, ..., dp[7] = dp[3]+1
    - from 0-7 we construct 8-16: similarly, etc.
    
    suppose we need to find i = 5
    */
    vector<int> countBits(int num) {
        int i = 1;
        vector<int> dp;
        dp.push_back(0);
        if (num == 0)
            return dp;
        
        while (i <= num) { // i = 1
            int n = dp.size(); // n = 1
            while (i-n < n && i <= num) {
                dp.push_back(dp[i-n]+1); // dp[2-2]+1 = 1
                i++;
            }
        }
        
        return dp;
    }
};