// https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        set<vector<int>> s;
        
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                int l = j+1;
                int r = n-1;

                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];

                    if (sum == target) {
                        vector<int> quad;
                        quad.push_back(nums[i]);
                        quad.push_back(nums[j]);
                        quad.push_back(nums[l]);
                        quad.push_back(nums[r]);
                        s.insert(quad);
                        l++; r--;
                    }
                    else if (sum < target)
                        l++;
                    else
                        r--;
                }
            }
        }
        
        for (auto quad : s)
            result.push_back(quad);
        
        return result;
    }
};