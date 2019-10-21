// https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        
        int currMax = arr[0], overallMax = arr[0];
        vector<int> forward (n);
        forward[0] = arr[0];
        for (int i = 1; i < n; i++) {
            currMax = max(arr[i], currMax+arr[i]);
            overallMax = max(currMax, overallMax);
            
            forward[i] = currMax;
        }
        
        currMax = arr[n-1], overallMax = arr[n-1];
        vector<int> backward (n);
        backward[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            currMax = max(arr[i], currMax+arr[i]);
            overallMax = max(currMax, overallMax);
            
            backward[i] = currMax;
        }
        
        int res = overallMax;
        for (int i = 1; i < n-1; i++) {
            res = max(res, forward[i-1] + backward[i+1]);
        }
        
        return res;
    }
};