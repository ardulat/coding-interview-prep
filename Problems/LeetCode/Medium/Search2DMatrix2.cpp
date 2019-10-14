// https://leetcode.com/problems/search-a-2d-matrix-ii/

/*
Brute-force: TLE
- each time eliminate 1/4 submatrices
*/
typedef pair<int,int> pr;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target, pr start, pr end) {
        int x1 = start.first, y1 = start.second;
        int x2 = end.first, y2 = end.second;
        // cout << "\n\nX1: " << x1 << " X2: " << x2 << endl;
        // cout << "Y1: " << y1 << " Y2: " << y2 << endl;
        if (start == end)
            return matrix[x1][y1] == target;
        
        if (x1 > x2 || y1 > y2 || x2 >= matrix.size() || y2 >= matrix[x2].size())
            return false;
        
        cout << (x2-x1) * (y2-y1) << endl;
        
        int midRow = (x1+x2)/2; // 3+3 / 2 = 3
        int midCol = (y1+y2)/2;
        
        if (matrix[midRow][midCol] == target)
            return true;
        else if (matrix[midRow][midCol] > target) { // look left-top
            // cout << "Search left-top" << endl;
            return searchMatrix(matrix, target, {x1, y1}, {midRow, midCol}) ||
                searchMatrix(matrix, target, {x1, midCol+1}, {midRow, y2}) ||
                searchMatrix(matrix, target, {midRow+1, y1}, {x2, midCol});
        }
        else { // look right-bottom
            // cout << "Search right-bottom" << endl;
            return searchMatrix(matrix, target, {midRow+1, midCol+1}, {x2, y2}) ||
                searchMatrix(matrix, target, {x1, midCol+1}, {midRow, y2}) ||
                searchMatrix(matrix, target, {midRow+1, y1}, {x2, midCol});
        }
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        
        return searchMatrix(matrix, target, {0,0}, {matrix.size()-1, matrix[0].size()-1});
    }
};



/*
Accepted:
- reduce 3 submatrices before to two by iterating over mid column
*/

typedef pair<int,int> pr;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target, pr start, pr end) {
        int x1 = start.first, y1 = start.second;
        int x2 = end.first, y2 = end.second;
        
        if (x1 > x2 || y1 > y2 || x2 >= matrix.size() || y2 >= matrix[x2].size())
            return false;
        
        int mid = (y1+y2)/2;
        
        // fix column, start searching for row
        int i = x1;
        while (i <= x2) {
            if (matrix[i][mid] == target)
                return true;
            
            else if (matrix[i][mid] > target)
                break;
            
            i++;
        }
        
        i = min(i, x2); // in case out of bounds
        
        return searchMatrix(matrix, target, {i, y1}, {x2, mid-1}) ||
            searchMatrix(matrix, target, {x1, mid+1}, {i, y2});
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())
            return false;
        
        return searchMatrix(matrix, target, {0,0}, {matrix.size()-1, matrix[0].size()-1});
    }
};