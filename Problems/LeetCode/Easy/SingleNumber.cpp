// https://leetcode.com/problems/single-number/submissions/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            res = res ^ nums[i];
        }
        
        return res;
    }
};