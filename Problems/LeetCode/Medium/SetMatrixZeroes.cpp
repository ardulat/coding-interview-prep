// https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    /*
    Brute-force: O(m+n) space
    - traverse our matrix and push zero rows and zero cols into sets
    - traverse once again and set matrix[i][j] to zero in case i and j is in the preprocessed set
    
    Time: O(nm)
    */
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows, cols; // zero rows and zero cols
        
        int n = matrix.size(), m = matrix[0].size();
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (rows.find(i) != rows.end() || cols.find(j) != cols.end())
                    matrix[i][j] = 0;
    }
};

// Costant space with manipulation of the original array
class Solution {
public:
    /*
    Optimized: O(1) space
    - use first col and first row to store all flags (zero cols and rows)
    - change the matrix according to the first col and first row
    
    Time: O(2N) = O(N)
    */
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        
        // check whether we need to zero out the first column
        bool zeroCol = false;
        for (int i = 0; i < n; i++)
            if (matrix[i][0] == 0) {
                zeroCol = true;
                break; // no need to move on
            }
        
        // check whether we need to zero out the first row
        bool zeroRow = false;
        for (int j = 0; j < m; j++)
            if (matrix[0][j] == 0) {
                zeroRow = true;
                break;
            }
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
        
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        
        // zero first col and row if needed
        if (zeroCol)
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
        
        if (zeroRow)
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;
    }
};