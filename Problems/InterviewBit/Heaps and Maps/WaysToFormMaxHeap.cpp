// https://www.interviewbit.com/problems/ways-to-form-max-heap/

// Compiler note: Your code might be failing for larger test-cases

long long choose(int n, int k, vector<vector<int>> &C) {
    if (k > n)
        return 0;
    if (n <= 1)
        return 1;
    if (k == 0)
        return 1;
        
    if (C[n][k] != -1) 
        return C[n][k]; 
  
    int ans = choose(n-1, k-1, C) + choose(n-1, k, C); 
    C[n][k] = ans; 
    return ans; 
}

int countLeft(int n) {
    if (n == 1)
        return 0;
    int h = (int) log2( (double) n);
    int maxLast = pow(2, h);
    int last = n-(maxLast-1);
    // if last more then half-filled
    if (last >= maxLast/2)
        return maxLast-1;
    return maxLast-1-((maxLast/2)-last);
}

int Solution::solve(int A) {
    if (A <= 2)
        return 1;
    int left = countLeft(A);
    vector<vector<int>> C(100, vector<int>(100, -1));
    return (choose(A-1, left, C) % 1000000007 * (solve(left) % 1000000007 * solve(A-1-left) % 1000000007) % 1000000007) % 1000000007;
}
