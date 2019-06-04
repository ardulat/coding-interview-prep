// https://leetcode.com/problems/subsets/

class Solution {
public:
    /*
    nums = [1,2]
    result = [
        [1],
        [2],
        [1,2],
        []
    ]
    */
    void backtrack(vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& result) {
        result.push_back(subset);
        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtrack(nums, i+1, subset, result);
            subset.pop_back();
        }
    }
    // nums is distinct
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        backtrack(nums, 0, subset, result);
        
        return result;
    }
};