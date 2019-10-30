// 

// Top-down dynamic programming - O(N^2) TLE
class Solution {
private:
    vector<bool> dp;
public:
    bool canJump(vector<int>& nums, int idx) {
        if (idx >= nums.size()-1) // reached the last index
            return true;
        
        if (!dp[idx])
            return false;

        int jumpLen = nums[idx]; // max possible jump length
        
        for (int i = jumpLen; i > 0; i--) {
            if (canJump(nums, idx+i))
                return true;
        }
        
        dp[idx] = false;
        
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        this->dp = vector<bool>(n, true);
        
        return canJump(nums, 0);
    }
};

// Bottom-up dynamic programming - O(N^2) TLE

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        
        dp[n-1] = true; // last is labeled as GOOD position
        
        for (int i = n-2; i >= 0; i--) {
            int jumpLen = nums[i]; // max jumping length
            
            for (int j = jumpLen; j > 0; j--) {
                if (i+j >= n-1 || dp[i+j]) {
                    dp[i] = true;
                    break;
                }
            }            
        }
        
        return dp[0] == true;
    }
};

// Greedy - O(N)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        int lastGoodIndex = n-1;
        
        for (int i = n-2; i >= 0; i--) {
            int jumpLen = nums[i]; // max jumping length
            
            if (i+jumpLen >= lastGoodIndex)
                lastGoodIndex = i;
        }
        
        return lastGoodIndex == 0;
    }
};