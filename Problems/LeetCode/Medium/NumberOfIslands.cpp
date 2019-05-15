// https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    void DFSMark(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()
            || grid[i][j] == '0') return;
        grid[i][j] = '0'; // mark as visited
        DFSMark(grid,i,j-1);
        DFSMark(grid,i,j+1);
        DFSMark(grid,i-1,j);
        DFSMark(grid,i+1,j);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == '1') {
                    DFSMark(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};