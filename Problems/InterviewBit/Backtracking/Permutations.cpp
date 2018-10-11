// https://www.interviewbit.com/problems/permutations/

void permute_helper(vector<int> A, int start, int end, vector<vector<int>> &result) {
    if (start == end) {
        result.push_back(A);
        return;
    }
    for (int i = start; i < end; i++) {
        swap(A[start], A[i]);
        permute_helper(A, start+1, end, result);
        swap(A[start], A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    vector<vector<int>> result;
    int n = A.size();
    
    permute_helper(A, 0, n, result);
    return result;
}
