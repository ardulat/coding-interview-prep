// https://leetcode.com/problems/flipping-an-image/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n/2; j++)
                swap(A[i][j], A[i][n-1-j]);
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 0)
                    A[i][j] = 1;
                else
                    A[i][j] = 0;
            }
        
        return A;
    }
};