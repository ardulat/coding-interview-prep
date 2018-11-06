// https://leetcode.com/problems/longest-consecutive-sequence/

// Approach: use hashset, insert all elements there,
//           find the potential first element in the sequence,
//           start a sequence by looking for ascending numbers of the start,
//           count them, and compare with max

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset;
        
        for (int i = 0; i < nums.size(); i++)
            hashset.insert(nums[i]);
        
        int maxLength = 0;
        for (int i = 0; i < nums.size(); i++) {
            // if it's the first element in sequence
            if (hashset.find(nums[i]-1) == hashset.end()) {
                int j = nums[i];
                while (hashset.find(j) != hashset.end())
                    j++;
                maxLength = max(maxLength, j-nums[i]);
            }
        }
        
        return maxLength;
    }
};