// https://www.interviewbit.com/problems/single-number/

int Solution::singleNumber(const vector<int> &A) {
    
    int result = A[0];
    
    for (int i = 1; i < A.size(); i++) {
        result = result ^ A[i];
    }
    
    return result;
}
