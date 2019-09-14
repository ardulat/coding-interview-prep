// https://leetcode.com/problems/continuous-subarray-sum/

class Solution {
public:
    /*
    sum(j..i) % K = ((sum(0..i) % K) - (sum(0..j) % K)) == 0
    a-b = 0
    a = b
    
    idea: map sums to index like sum(0,i) => i
    */
    bool checkSubarraySum(vector<int>& nums, int k) {
        int runningTotal = 0;
        unordered_map<int,int> seen;
        seen[0] = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            runningTotal += num;
            
            if (k != 0)
                runningTotal = runningTotal % k;
            
            if (seen.find(runningTotal) != seen.end()) {
                if (i-seen[runningTotal] > 1) 
                    return true;
            } else
                seen[runningTotal] = i;
        }
        
        return false;
    }
};