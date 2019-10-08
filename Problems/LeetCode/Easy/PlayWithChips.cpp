// https://leetcode.com/problems/play-with-chips/

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int even = 0, odd = 0;
        
        for (int num : chips) {
            if (num % 2 == 0)
                even++;
            else
                odd++;
        }
        
        return min(odd, even);
    }
};