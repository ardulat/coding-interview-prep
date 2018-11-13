// https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n-1;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if ((mid == 0 || nums[mid-1] <= nums[mid]) && 
                (mid == n-1 || nums[mid+1] <= nums[mid]))
                return mid;
            
            else if (mid > 0 && nums[mid-1] > nums[mid])
                end = mid-1;
            else
                start = mid+1;
        }
        
        return -1;
    }
};