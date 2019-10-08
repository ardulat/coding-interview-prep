// https://leetcode.com/problems/fibonacci-number/

class Solution {
private:
    unordered_map<int,int> dp;
    
public:
    int fib(int N) {
        if (N < 2) {
            dp[N] = N;
            return N;
        }
        if (dp.find(N) != dp.end())
            return dp[N];
        
        dp[N] = fib(N-1) + fib(N-2);
        
        return dp[N];
    }
};