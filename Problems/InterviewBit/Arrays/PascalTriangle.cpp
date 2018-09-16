// https://www.interviewbit.com/problems/pascal-triangle/

vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> result;
    int numRows = A; // for convenience
    if (numRows > 0) {
        result.push_back({1});
        if (numRows > 1) {
            result.push_back({1,1});
            if (numRows > 2) {
                for (int i = 3; i <= numRows; i++) {
                    vector<int> row;
                    row.push_back(1);
                    vector<int> previous_row = result[i-2];
                    
                    for (int j = 1; j < i-1; j++) {
                        int sum = previous_row[j] + previous_row[j-1];
                        row.push_back(sum);
                    }
                    row.push_back(1);
                    result.push_back(row);
                }
            }
        }
    }
    
    return result;
}
