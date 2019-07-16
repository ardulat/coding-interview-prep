// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void combinationSum(vector<int>& candidates, int start, int target, vector<int> comb, vector<vector<int>>& res) {
        if (!target) {
            res.push_back(comb);
            return;
        }
        if (target < 0)
            return;
        for (int i = start; i < candidates.size(); i++) {
            int num = candidates[i];
            comb.push_back(num);
            combinationSum(candidates, i, target-num, comb, res);
            comb.pop_back();
        }
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        combinationSum(candidates, 0, target, vector<int>(), res);
        return res;
    }
};