// https://www.interviewbit.com/problems/prettyprint/

vector<vector<int> > Solution::prettyPrint(int A) {
    int n = (A-1)*2+1; // size of matrix
    vector<vector<int>> M(n, vector<int> (n, 0)); // n by n matrix
    int i = 0; // counter
    
    while (A > 0) {
        for (int j = i; j < (n-i); j++) {
            M[j][i] = A; // M[0:n, 0]
            M[i][j] = A; // M[0, 0:n]
            M[n-i-1][j] = A; // M[n, 0:n]
            M[j][n-i-1] = A; // M[0:n, n]
        }
        
        A = A-1;
        i++;
    }
    return M;
}
