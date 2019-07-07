// https://leetcode.com/problems/max-increase-to-keep-city-skyline/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> horizontal(n, 0), vertical(n, 0);
        for (int i = 0; i < n; i++) {
            int horizontalMax = -1, verticalMax = -1;
            for (int j = 0; j < n; j++) {
                horizontalMax = max(grid[i][j], horizontalMax);
                verticalMax = max(grid[j][i], verticalMax);
            }
            horizontal[i] = horizontalMax;
            vertical[i] = verticalMax;
        }
        int count = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                count += min(horizontal[i], vertical[j]) - grid[i][j];
            
        return count;
    }
};