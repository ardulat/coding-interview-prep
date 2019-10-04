// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

class Solution {
public:
    /*
    Suggested by Leetcode: O(N)
    - count the number of remainders (time[i] % 60 = r)
    - store in array of size 60 (0..59)
    - traverse array till middle element:
        - if both rems[i] and rems[n-i] are nonzero
        - count (rems[i] * rems[n-i]) - each pair can be used twice
        - add it to result
    - edge case for r = 0: n*(n-1)/2 <=> n choose 2
    - edge case for r = 30: n*(n-1)/2 <=> n choose 2
    
    */
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> rems(60, 0);
        for (int t : time) {
            int r = t % 60;
            rems[r]++;
        }
        
        int n = rems.size();
        int res = 0;
        
        // edge case for r = 0
        res += rems[0] * (rems[0]-1) / 2;
        
        for (int i = 1; i < n/2; i++)
            res += rems[i] * rems[n-i];
        
        // edge case for r = 30
        res += rems[n/2] * (rems[n/2]-1) / 2;
        
        return res;
    }
};