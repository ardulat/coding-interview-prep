// https://leetcode.com/problems/contiguous-array/

class Solution {
    public:
        /*
        orig = [ 0,1,1, 0,1, 0]
        conv = [-1,1,1,-1,1,-1]
        sums = [-1,0,1, 0,1, 0]
        sums[j,i] = sums[i] - sums[j-1]
        trick: store all (sums[i], i) pairs in hashmap (only first occurring)
        objective -> largest interval [i,j]
        
        orig = [ 0,1,1,1,1,1, 0, 0, 0,1, 0, 0, 0]
        conv = [-1,1,1,1,1,1,-1,-1,-1,1,-1,-1,-1]
        sums = [-1,0,1,2,3,4, 3, 2, 1,2, 1, 0,-1]
        ind  = [ 0,1,2,3,4,5, 6, 7, 8,9,10,11,12]
        
        orig = [ 0,1, 0]
        conv = [-1,1,-1]
        sums = [-1,0,-1]
        ind  = [ 0,1, 2]
        
        1) if sums[i] == 0, then maxLen = i+1 (from the beginning)
        2) if (sums[i], j) in hashmap, then interval is [j+1, i], maxLen = i-j
        
        */
        int findMaxLength(vector<int>& nums) {
            int maxLen = 0;
            int n = nums.size();
            
            // step 1: convert the array to +1/-1
            for (int i = 0; i < n; i++)
                if (nums[i] == 0)
                    nums[i] = -1;
            
            // step 2: compute sums[i]
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += nums[i];
                nums[i] = sum;
            }
            
            // step 3: use hashmap to find the longest interval
            unordered_map<int,int> hashmap;
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) // starting from the beginning
                    maxLen = i+1;
                
                if (hashmap.find(nums[i]) == hashmap.end())
                    hashmap[nums[i]] = i;
                else
                    maxLen = max(maxLen, i-hashmap[nums[i]]);
            }
            
            return maxLen;
        }
    };