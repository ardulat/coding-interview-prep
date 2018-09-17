// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

// uses only O(k) extra space
vector<int> Solution::getRow(int k) {
    vector<int> result;
    if (k == 0)
        result = {1};
    if (k == 1)
        result = {1,1};
    if (k > 1) {
        vector<int> previousRow = getRow(k-1);
        vector<int> currentRow;
        currentRow.push_back(1);
        
        for (int i = 1; i < k; i++) {
            int sum = previousRow[i] + previousRow[i-1];
            currentRow.push_back(sum);
        }
        currentRow.push_back(1);
        result = currentRow;
    }
    return result;
}
