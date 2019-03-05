int climbStairsUtil(int i, vector<int> &memo) {
    if (i == 0 || i == 1) return 1;
    
    if (memo[i] == 0) {
        memo[i] = climbStairsUtil(i-1, memo) + climbStairsUtil(i-2, memo);
    }
        
    return memo[i];
}

int Solution::climbStairs(int A) {
    vector<int> memo(A+1, 0);
    return climbStairsUtil(A, memo);
}
