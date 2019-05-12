// https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int m = n/2;
        unordered_map<int, int> ht;
        
        // count all occurences
        for (int i = 0; i < n; i++) {
            if (ht.find(nums[i]) == ht.end())
                ht[nums[i]] = 1;
            else
                ht[nums[i]]++;
        }
        
        // find the majority element by number of occurences
        for (auto& it : ht) {
            if (it.second > m)
                return it.first;
        }
        return -1;
    }
};