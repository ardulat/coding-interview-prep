// https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        // better solution would be to extend our array
        vector<int> newNums (nums.size()+2, 0);
        newNums[0] = newNums[nums.size()+1] = INT_MIN;
        
        for (int i = 0; i < nums.size(); i++)
            newNums[i+1] = nums[i];
        
        int start = 1, end = nums.size();
        
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (newNums[mid] >= newNums[mid+1] && newNums[mid] >= newNums[mid-1])
                return mid-1;
            else if (newNums[mid-1] <= newNums[mid] && newNums[mid] <= newNums[mid+1])
                start = mid+1;
            else
                end = mid-1;
        }
        
        return -1;
    }
};