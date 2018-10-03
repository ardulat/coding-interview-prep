// https://www.interviewbit.com/problems/min-xor-value/

// Brute-force:
int Solution::findMinXor(vector<int> &A) {
    int min = A[0]^A[1];
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            int temp = A[i]^A[j];
            // cout << A[i] << "," << A[j] << ":\t" << temp << endl;
            if (temp < min && i != j) {
                min = temp;
            }
        }
    }
    // cout << endl;
    return min;
}

// Better solution:
// Sort, and then find min from every contigous pairs
int Solution::findMinXor(vector<int> &A) {
    
    sort(A.begin(), A.end()); // O(NlogN)
    
    int min = A[0]^A[1];
    for (int i = 0; i < A.size()-1; i++) {
        int temp = A[i]^A[i+1];
        if (temp < min)
            min = temp;
    }
    
    return min;
}
