// https://leetcode.com/problems/product-of-array-except-self/

// Approach:
// 1. Initialize the output array
// 2. push all left products (product of elements to the left of ith element)
//    to the output array
// 3. traverse the output array, and multiply (left product) to the right products

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        
        int temp = 1;
        for (int i = 0; i < n; i++) {
            result.push_back(temp);
            temp = temp * nums[i];
        }
        
        temp = 1;
        for (int i = n-1; i >= 0; i--) {
            result[i] = result[i] * temp;
            temp = temp * nums[i];
        }
        
        return result;
    }
};