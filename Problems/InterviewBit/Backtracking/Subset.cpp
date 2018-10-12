// https://www.interviewbit.com/problems/subset/

void subsets_helper(vector<int> &A, vector<vector<int>> &results, vector<int> &subset, int index) {
    for (int i = index; i < A.size(); i++) {
        subset.push_back(A[i]);
        results.push_back(subset);
        
        subsets_helper(A, results, subset, i+1);
        
        subset.pop_back();
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>> results;
    vector<int> subset;
    // include null subset:
    results.push_back(subset);
    // sort first
    sort(A.begin(), A.end());
    
    int index = 0;
    subsets_helper(A, results, subset, index);
    
    return results;
}
