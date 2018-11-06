// https://leetcode.com/problems/search-in-rotated-sorted-array/

// Approach:
// 1. find min element (with binary search - look for special feature)
// 2. compare with the first element, and thus, determine in which subarray to search
// 3. run binary search on either left, or right subarray

class Solution {
public:
    int findMin(vector<int>& nums, int start, int end) {
        // base case: one element array
        if (start == end)
            return start;
        if (start < end) {
            int mid = (start+end)/2;
            // feature we are looking for: preceeding element is higher than next
            if (nums[mid] > nums[mid+1])
                return mid+1;
            if (nums[mid-1] > nums[mid+1])
                return mid;
            if (nums[mid] < nums[start]) // go left
                return findMin(nums, start, mid-1);
            return findMin(nums, mid+1, end); // go right
        }
        // edge case: the array is not rotated
        return -1;
    }
    
    int binarySearch(vector<int>& nums, int start, int end, int target) {
        if (start <= end) {
            int mid = (start+end)/2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                return binarySearch(nums, start, mid-1, target);
            return binarySearch(nums, mid+1, end, target);
        }
        
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int minIndex = findMin(nums, 0, nums.size()-1);
        cout << minIndex << endl;
        
        // edge case: the array is not rotated
        if (minIndex == -1)
            return -1;
        
        if (nums[minIndex] == target)
            return minIndex;
        if (target >= nums[0]) // search in left subarray
            return binarySearch(nums, 0, minIndex-1, target);
        return binarySearch(nums, minIndex+1, nums.size()-1, target);
    }
};