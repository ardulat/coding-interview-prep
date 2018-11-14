// https://leetcode.com/problems/subarray-sum-equals-k

/*
Approach: sum(i,j) = sum(0,j)-sum(0,i)

1. Track the current sum (0, i) in variable currsum
2. Track the number of occurences of each currsum in a map
3. While traversing the array:
    - add ith element to the currsum
    - check whether the currsum is equal to the desired sum
    - check whether sum(0,j) which equals to sum(0,i)-k is present in the map
    - if present, add occurences
    - Add occurence currsum to the map
*/
 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int currsum = 0, n = nums.size(), i = 0;
        int res = 0;
        
        unordered_map<int, int> sum2Count;
        
        while (i < n) {
            currsum += nums[i];
            
            if (currsum == k)
                res++;
            
            if (sum2Count.find(currsum-k) != sum2Count.end())
                res += sum2Count[currsum-k];
            
            sum2Count[currsum]++;
            i++;
        }
        
        return res;
    }
};