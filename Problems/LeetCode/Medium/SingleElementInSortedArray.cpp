// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int binarySearch(vector<int>& nums, int start, int end) {
        while (start <= end) {
            int mid = (start+end)/2;
            if ((mid-1 < 0 || nums[mid] != nums[mid-1]) &&
                (mid+1 >= nums.size() || nums[mid] != nums[mid+1]))
                return nums[mid];
            int size = end-start+1;
            int leftsize, rightsize;
            if (nums[mid]==nums[mid+1]) {
                leftsize = mid-start; // 1
                rightsize = size-leftsize;
                if (rightsize == 0 || leftsize % 2 == 1) end = mid-1;
                else start = mid;
            }
            else {
                leftsize = mid+1-start;
                rightsize = size-leftsize;
                if (leftsize % 2 == 0) start = mid+1;
                else end = mid;
            }
        }
        return -1;
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        return binarySearch(nums, 0, nums.size()-1);
    }
};