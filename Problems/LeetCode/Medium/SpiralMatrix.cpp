// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return vector<int>();
        int n = matrix[0].size();
        vector<int> result(m*n);
        int firstColumn = 0, firstRow = 0, lastColumn = n-1, lastRow = m-1;
        int idx = 0;
        int dir = 1;
        while (idx < m*n) {
            if (dir == 1) {
                int initial = idx;
                for (int i = firstColumn; i <= lastColumn; i++) {
                    result[idx] = matrix[firstRow][i];
                    idx++;
                }
                if (initial != idx) firstRow++;
                dir = 2;
            }
            else if (dir == 2) {
                int initial = idx;
                for (int i = firstRow; i <= lastRow; i++) {
                    result[idx] = matrix[i][lastColumn];
                    idx++;
                }
                if (initial != idx) lastColumn--;
                dir = 3;
            }
            else if (dir == 3) {
                int initial = idx;
                for (int i = lastColumn; i >= firstColumn; i--) {
                    result[idx] = matrix[lastRow][i];
                    idx++;
                }
                if (initial != idx) lastRow--;
                dir = 4;
            }
            else if (dir == 4) {
                int initial = idx;
                for (int i = lastRow; i >= firstRow; i--) {
                    result[idx] = matrix[i][firstColumn];
                    idx++;
                }
                if (initial != idx) firstColumn++;
                dir = 1;
            }
        }
        return result;
    }
};