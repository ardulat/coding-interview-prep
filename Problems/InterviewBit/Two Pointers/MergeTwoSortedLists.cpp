// https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/

void Solution::merge(vector<int> &A, vector<int> &B) {
    int i = 0, j = 0, k = 0;
    vector<int> result(A.size()+B.size(), 0);
    
    while(i < A.size() && j < B.size()) {
        if (A[i] >= B[j]) {
            result[k] = B[j];
            j++;
        }
        else {
            result[k] = A[i];
            i++;
        }
        k++;
    }
    
    while(i < A.size()) {
        result[k] = A[i];
        i++; k++;
    }
    while(j < B.size()) {
        result[k] = B[j];
        j++; k++;
    }
    A = result;
}
