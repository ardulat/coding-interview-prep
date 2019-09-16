// https://leetcode.com/problems/divisor-game/

// Top-down dynamic programming approach
class Solution {
public:
    bool divisorGame(int N, vector<bool>& memoize) {
        if (memoize.size() >= N)
            return memoize[N-1];
        
        bool res = false;
        
        for (int x = 1; x < N; x++) {
            if (N % x == 0 && !divisorGame(N-x, memoize)) {
                res = true;
                break;
            }
        }
        
        memoize.push_back(res);
        
        return res;
    }
    
    bool divisorGame(int N) {
        vector<bool> memoize;
        memoize.push_back(false); // N = 0
        return divisorGame(N, memoize);
    }
};