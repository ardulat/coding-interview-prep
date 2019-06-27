// https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    /*
    [1,2] -> [[], [1], [2], [1,2]]
    [1,2,3] -> [[], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3]]
    */
    set<vector<int>> generateSubsets(vector<int>& nums, int start, int end) {
        set<vector<int>> res;
        if (end == start) { // 0
            vector<int> subset;
            res.insert(subset); // empty
            subset.push_back(nums[start]);
            res.insert(subset);
            return res;
        }
        set<vector<int>> prev = generateSubsets(nums, start, end-1);
        res = prev; // copy constructor
        for (vector<int> p : prev) {
            p.push_back(nums[end]);
            res.insert(p);
        }
        return res;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) {
            res.push_back(vector<int>());
            return res;
        }
        sort(nums.begin(), nums.end());
        for (vector<int> subset : generateSubsets(nums, 0, nums.size()-1))
            res.push_back(subset);
        return res;
    }
};