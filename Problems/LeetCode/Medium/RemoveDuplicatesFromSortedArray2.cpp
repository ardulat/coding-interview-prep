// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int idx = 1, i = 1;
        int cur = nums[0], count = 1;
        while (i < nums.size()) {
            if (nums[i] == cur)
                count++;
            else {
                cur = nums[i];
                count = 1;
            }
            nums[idx] = cur;
            if (count < 3)
                idx++;
            i++;
        }
        return idx;
    }
};