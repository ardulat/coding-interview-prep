// https://www.interviewbit.com/problems/minimize-the-absolute-difference/

int maxOfThree(int a, int b, int c) {
    return max({a,b,c});
}

int minOfThree(int a, int b, int c) {
    return min({a,b,c});
}

int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i = 0, j = 0, k = 0;
    int maxAbsDiff = INT_MAX;
    
    while (i<A.size() && j<B.size() && k<C.size()) {
        
        if (maxAbsDiff > abs(maxOfThree(A[i],B[j],C[k])-minOfThree(A[i],B[j],C[k])))
            maxAbsDiff = abs(maxOfThree(A[i],B[j],C[k])-minOfThree(A[i],B[j],C[k]));
        
        if (minOfThree(A[i],B[j],C[k]) == A[i]) {
            i++;
        }
        else if (minOfThree(A[i],B[j],C[k]) == B[j]) {
            j++;
        }
        else if (minOfThree(A[i],B[j],C[k]) == C[k]) {
            k++;
        }
    }
    return maxAbsDiff;
}
