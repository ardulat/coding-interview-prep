// https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    int n = A.size(), m = B.size();
    int i = 0, j = 0;
    vector<int> result;
    
    while (i < n && j < m) {
        if (A[i] < B[j])
            i++;
        else if (A[i] > B[j])
            j++;
        else { // A[i] == B[j]
            result.push_back(A[i]);
            i++; j++;
        }
    }
    return result;
}
