// https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) // already at the last position
            return 0;
        
        int start = 0, end = 0;
        int steps = 0; // number of steps covered now
        
        while (end < n) {
            int farthest = end;
            
            for (int i = start; i <= end; i++) {
                int jumpLen = nums[i]; // 3
                
                farthest = max(farthest, i + jumpLen); // 4
            }
            
            steps++;
            
            if (farthest >= n-1)
                return steps;
            
            start = end+1;
            end = farthest;
        }
        
        return steps;
    }
};