// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<int> generate(int numRows, vector<vector<int>>& res) {
        if (numRows < 3) {
            vector<int> cur;
            if (numRows == 0)
                return cur;
            cur.push_back(1);
            res.push_back(cur);
            if (numRows == 1)
                return cur;
            cur.push_back(1);
            res.push_back(cur);
            return cur;
        }
        vector<int> prev = generate(--numRows, res);
        vector<int> cur;
        cur.push_back(1); // left one
        for (int i = 0; i < prev.size()-1; i++) {
            int sum = prev[i] + prev[i+1];
            cur.push_back(sum);
        }
        cur.push_back(1); // right one
        res.push_back(cur);
        return cur;
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        generate(numRows, res);
        return res;
    }
};