// https://www.interviewbit.com/problems/diffk/

int Solution::diffPossible(vector<int> &A, int B) {
    int i = 0, j = 1;
    
    while (j < A.size()) {
        int diff = A[j]-A[i];
        if (diff == B)
            return 1;
        else if (diff > B) {
            i++;
            if (i == j)
                j++;
        }
        else
            j++;
    }
    return 0;
}
