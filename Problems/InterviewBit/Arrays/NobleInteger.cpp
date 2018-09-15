// https://www.interviewbit.com/problems/noble-integer/

// Brute-force:
int Solution::solve(vector<int> &A) {
    for (int i = 0; i < A.size(); i++) {
        int candidate = A[i];
        int greater = 0;
        for (int j = 0; j < A.size(); j++)
            if (A[j] > candidate)
                greater++;
        if (greater == candidate)
            return 1;
    }
    return -1;
}

// Optimal:
int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size()-1; i++) {
        int greater = A.size() - (i+1);
        if (A[i] == greater && A[i+1] != A[i])
            return 1;
    }
    if (A[A.size()-1] == 0) // potomu chto nikto ego ne greater
        return 1;
    return -1;
}

// P.S. edge case of the year = [ -4, -2, 0, -1, -6 ]
