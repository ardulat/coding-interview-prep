// https://leetcode.com/problems/sort-colors/submissions/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        
        // traverse once:
        int i = 0;
        while (i < n) {
            // swap in-place:
            if (nums[i] == 0 && left < i) {
                swap(nums[i], nums[left]);
                left++;
            }
            else if (nums[i] == 2 && right > i) {
                swap(nums[i], nums[right]);
                right--;
            }
            else
                i++;
        }
    }
};