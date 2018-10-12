// https://www.interviewbit.com/problems/combinations/

// Discovery during solving: coffee really helps to cheer up if sleepy

void combinations(vector<int> A, int index, int k, int start, int end, vector<vector<int>> &results) {
    if (index == k) {
        for (int i = start; i <= end; i++) {
            A[index-1] = i;
            results.push_back(A);
        }
        return;
    }
    for (int i = start; i < end; i++) {
        A[index-1] = i;
        combinations(A, index+1, k, i+1, end, results);
    }
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<vector<int>> results;
    vector<int> M(B, 0); // inialize vector M of size B with values 0
    combinations(M, 1, B, 1, A, results);
    return results;
}
