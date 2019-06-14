// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

class Solution {
public:
    /*
    Since A[i] is in the range [1,n], all the numbers are positive.
    We can modify the array by making it negative.
    Find the numbers that are not negative.
    */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i])-1; // in the range [0,n-1]
            if (nums[num] > 0) // is positive
                nums[num] = -nums[num];
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
            if (nums[i] > 0)
                res.push_back(i+1);
        return res;
    }
};