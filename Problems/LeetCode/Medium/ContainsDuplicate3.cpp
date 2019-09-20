// https://leetcode.com/problems/contains-duplicate-iii/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s;
        
        for (int i = 0; i < nums.size(); i++) {
            long num = nums[i];
            if (s.size() > k)
                s.erase(nums[i-k-1]);
            
            // first number that is greater or equal to
            auto it = s.lower_bound(num-t);
            if (it != s.end() && abs(*it-num) <= t)
                return true;
            
            s.insert(num); // O(logK)
        }
        
        return false;
    }
};