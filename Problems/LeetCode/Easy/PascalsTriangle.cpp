// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<int> generate(int numRows, vector<vector<int>>& res) {
        if (numRows < 3) {
            vector<int> row;
            row.push_back(1);
            res.push_back(row);
            if (numRows == 1)
                return row;
            row.push_back(1);
            res.push_back(row);
            return row;
        }
        vector<int> prev = res.size() == numRows-1 ? res[numRows-2] : generate(numRows-1, res);
        vector<int> cur (prev.size()+1, 1); // row of size n+1 all filled with 1s
        for (int i = 0; i < prev.size()-1; i++)
            cur[i+1] = prev[i]+prev[i+1];
        res.push_back(cur);
        return cur;
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0)
            return res;
        generate(numRows, res);
        return res;
    }
};