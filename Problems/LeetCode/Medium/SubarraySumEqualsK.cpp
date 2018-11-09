// https://leetcode.com/problems/subarray-sum-equals-k

// Review the problem once again
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // create hashcode which will store sums from 0 to i
        unordered_map<int, int> hashmap;
        int n = nums.size();
        int count = 0;
        int sum = 0;
        hashmap[sum]++;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            
            if (hashmap.find(sum-k) != hashmap.end())
                count += hashmap[sum-k];
            
            hashmap[sum]++;
        }
        
        for (pair<int,int> pr : hashmap)
            cout << pr.first << " " << pr.second << endl;
        
        return count;
    }
};