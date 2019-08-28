// https://leetcode.com/problems/find-pivot-index/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, 0), right(n, 0);
        
        // step 1: construct left sums array
        int sum = 0;
        for (int i = 0; i < n; i++) {
            left[i] = sum;
            sum += nums[i];
        }
        
        // step 2: construct right sums array
        sum = 0;
        for (int i = n-1; i >= 0; i--) {
            right[i] = sum;
            sum += nums[i];
        }
        
        // step 3: compare left and right sums
        for (int i = 0; i < n; i++)
            if (left[i] == right[i])
                return i;
        
        // step 4: if there are no such sums, return -1
        return -1;
    }
};