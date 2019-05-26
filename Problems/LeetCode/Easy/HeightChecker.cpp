// https://leetcode.com/contest/weekly-contest-138/problems/height-checker/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        vector<int> sorted = heights;
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < heights.size(); i++)
            if (heights[i] != sorted[i])
                count++;
        return count;
    }
};