// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    pair<int,int> binarySearch(vector<int>& nums, int target, int start, int end) {
        if (start <= end) {
            int mid = (start+end)/2;
            if (nums[mid] == target) {
                // continue searching for the first and last positions
                int first, last;
                auto left = binarySearch(nums, target, start, mid-1);
                auto right = binarySearch(nums, target, mid+1, end);
                first = (left == make_pair(-1,-1)) ? mid : left.first;
                last = (right == make_pair(-1,-1)) ? mid : right.second;
                return {first, last};
            }
            else if (nums[mid] > target)
                return binarySearch(nums, target, start, mid-1);
            else
                return binarySearch(nums, target, mid+1, end);
        }
        return {-1,-1};
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        pair<int,int> pr = binarySearch(nums, target, 0, nums.size()-1);
        vector<int> res(2,0);
        res[0] = pr.first;
        res[1] = pr.second;
        return res;
    }
};