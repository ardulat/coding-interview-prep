// https://leetcode.com/problems/largest-number-at-least-twice-of-others/

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int largest = 0, idx = 0; // the range of nums[i] is [0, 99]
        
        // step 1: find the largest element
        for (int i = 0; i < n; i++)
            if (nums[i] > largest) {
                largest = nums[i];
                idx = i;
            }
        
        // step 2: compare the largest element
        for (int i = 0; i < n; i++) {
            if (largest != nums[i] && nums[i]*2 > largest)
                return -1;
        }
        
        // step 3: return index of the largest element
        return idx;
    }
};