// https://leetcode.com/problems/search-in-rotated-sorted-array/

// Approach:
// 1. find min element (with binary search - look for special feature)
// 2. compare with the first element, and thus, determine in which subarray to search
// 3. run binary search on either left, or right subarray

class Solution {
public:
    /*
    - find minimum element and its index
    - do the binary search for the two subarrays divided by the element
    */
    
    int findMin(vector<int>& nums, int start, int end) {
        if (start == end) // one element array
            return start;
        if (start < end) {
            int mid = (start+end)/2;
            if (mid > 0 && nums[mid-1] > nums[mid])
                return mid;
            if (mid-1 < nums.size() && nums[mid] > nums[mid+1])
                return mid+1;
            if (nums[mid] > nums[end])
                return findMin(nums, mid+1, end);
            return findMin(nums, start, mid-1);
        }
        return start; // the array is not rotated
    }
    
    int binarySearch(vector<int>& nums, int start, int end, int target) {
        if (start <= end) {
            int mid = (start+end)/2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                return binarySearch(nums, mid+1, end, target);
            return binarySearch(nums, start, mid-1, target);
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        // base case: empty array
        if (nums.empty())
            return -1;
        int minIndex = findMin(nums, 0, nums.size()-1);
        if (target == nums[minIndex])
            return minIndex;
        if (minIndex == 0)
            return binarySearch(nums, 0, nums.size()-1, target);
        if (target >= nums[0])
            return binarySearch(nums, 0, minIndex-1, target);
        return binarySearch(nums, minIndex+1, nums.size()-1, target);
    }
};