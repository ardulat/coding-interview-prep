// https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution {
public:
    /*
    1) convert recursive memoization to iterative dp solution
    2) count the number of sequences with length[i]
    
    */
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 1)
            return n;
        
        int maxLen = 1, currentMax;
        vector<int> length(n, 1); // max len starting from index i
        vector<int> counts(n, 1);
        
        for (int i = 1; i < n; i++) {
            
            for (int j = i-1; j >= 0; j--) {
                // prev seq = [1,3]
                // append 5
                // we can have seq [1,5] and [1,3,5]
                if (nums[i] > nums[j]) { // 5 > 3
                    
                    if (length[j]+1 > length[i]) // len is updated
                        counts[i] = counts[j];
                    else if (length[j]+1 == length[i]) // len are equal
                        counts[i] += counts[j];
                    
                    length[i] = max(length[i], length[j]+1);
                }
                // otherwise, do not append to seq
            }
            
            maxLen = max(maxLen, length[i]);
        }
        
        int res = 0;
        
        for (int i = 0; i < n; i++)
            if (length[i] == maxLen)
                res += counts[i];
        
        return res;
    }
};