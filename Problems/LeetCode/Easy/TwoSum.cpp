// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        
        for (int i = 0; i < nums.size(); i++)
            hashmap[nums[i]] = i;
        
        for (int i = 0; i < nums.size(); i++)
            if (hashmap.find(target-nums[i]) != hashmap.end())
                if (hashmap[target-nums[i]] != i) {
                    vector<int> result;
                    result.push_back(i);
                    result.push_back(hashmap[target-nums[i]]);
                    return result;
                }
    }
};