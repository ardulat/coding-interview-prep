// https://leetcode.com/problems/rotate-image/

class Solution {
public:
    /*
    [1,2,3],
    [4,5,6],
    [7,8,9]
    
    - transpose
    - horizontal swap
    */
    
    void print(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // cout << "original matrix: "<<endl;
        // print(matrix);
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        
        // print(matrix);
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n/2; j++)
                swap(matrix[i][j], matrix[i][n-1-j]);
        
        // print(matrix);
        
    }
};