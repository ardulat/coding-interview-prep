// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;
        while (start < end) {
            int mid = (start+end)/2;
            if (mid > 0 && nums[mid-1] > nums[mid])
                return nums[mid];
            if (mid+1 < n && nums[mid] > nums[mid+1])
                return nums[mid+1];
            if (nums[start] < nums[mid]) // 4, 7
                start = mid+1;
            else
                end = mid-1;
        }
        return nums.empty() ? -1 : nums[0]; // not rotated
    }
};