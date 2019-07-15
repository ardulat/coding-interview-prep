// https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        while (start <= end) {
            int mid = (start+end)/2;
            
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target && (mid+1 > nums.size()-1 || target < nums[mid+1]))
                return mid+1;
            if (nums[mid] < target)
                start = mid+1;
            if (nums[mid] > target)
                end = mid-1;
        }
        return 0;
    }
};