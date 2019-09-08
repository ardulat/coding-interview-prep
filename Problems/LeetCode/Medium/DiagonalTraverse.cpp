// https://leetcode.com/problems/diagonal-traverse/

class Solution {
public:
    /*
        [
         [ 1, 2, 3 ],
         [ 4, 5, 6 ],
         [ 7, 8, 9 ]
        ]
        
        [1,2,4,7,5,3,6,8,9]
    */
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;
        
        int N = matrix.size(), M = matrix[0].size();
        int row = 0, col = 0;
        int diag_idx = row+col;
        // row+col = diagonal index (0, 1, 2, ...)
        while (diag_idx <= N+M-2) {
            int i, j;
            if (diag_idx % 2 == 0) { // even index -> up
                i = diag_idx, j = 0;
                while (i >= 0 && j <= diag_idx) {
                    // cout << i << " " << j << endl;
                    if (i < N && j < M)
                        res.push_back(matrix[i][j]);
                    i--;
                    j++;
                }
            }
            else { // odd index -> down
                i = 0, j = diag_idx;
                while (i <= diag_idx && j >= 0) {
                    // cout << i << " " << j << endl;
                    if (j < M && i < N)
                        res.push_back(matrix[i][j]);
                    i++;
                    j--;
                }
            }
            diag_idx++;            
        }
        
        return res;
    }
};