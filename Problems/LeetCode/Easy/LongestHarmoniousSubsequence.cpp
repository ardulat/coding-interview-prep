// https://leetcode.com/problems/longest-harmonious-subsequence/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        // step 1: put all number with occurences in map
        unordered_map<int,int> hashmap;
        for (int num : nums)
            hashmap[num]++;
        
        // step 2: find the largest occurence of pair with diff exactly 1
        int maxTotal = 0;
        for (auto pr : hashmap) {
            int number = pr.first;
            int occurrence = pr.second;
            
            int prev = 0, next = 0;
            
            if (hashmap.count(number-1) > 0)
                prev = hashmap[number-1];
            if (hashmap.count(number+1) > 0)
                next = hashmap[number+1];
            
            int longer = max(prev, next);
            
            if (longer == 0)
                continue;
            
            maxTotal = max(maxTotal, longer+occurrence);
        }
        
        return maxTotal;
    }
};