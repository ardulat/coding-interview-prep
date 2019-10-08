// https://leetcode.com/problems/path-with-maximum-gold/

class Solution {
public:
    /*
    Brute-force: O(n^2)
    - run dfs under the conditions from each cell
    
    note: in order to not to use extra memory for "visited" matrix, simply alter the values in the grid
    
    Possible optimization: DP
    - store maximum gold obtained from the current cell (i,j)-position
    */
    void dfs(vector<vector<int>>& grid, int i, int j, int cur, int& res) {
        if (i >= 0 && i < grid.size() && j >= 0 && j < grid[i].size()) { // grid constraints
            int gold = grid[i][j];
            
            if (gold == -1) // visited
                return;
            if (gold == 0) { // calculate max result
                res = max(res, cur);
                return;
            }
            
            cur += gold; // collect the gold
            grid[i][j] = -1; // mark as visited
            
            // recur
            dfs(grid, i+1, j, cur, res);
            dfs(grid, i-1, j, cur, res);
            dfs(grid, i, j+1, cur, res);
            dfs(grid, i, j-1, cur, res);
            
            // backtrack
            grid[i][j] = gold;
        }
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int res = 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                dfs(grid, i, j, 0, res);
            }
        }
        
        return res;
    }
};