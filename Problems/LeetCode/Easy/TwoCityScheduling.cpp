// https://leetcode.com/problems/two-city-scheduling/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sz = costs.size(); // 2N
        
        // step 1: store all differences in ordered hashmap
        map<int,vector<int>> hashmap;
        
        for (int i = 0; i < sz; i++) {
            int first = costs[i][0];
            int second = costs[i][1];
            
            int diff = first - second;
            
            hashmap[diff].push_back(i); // diff maybe non-unique
        }
        
        int total = 0;
        int cnt = 0;
        for (auto pr : hashmap) {
            int diff = pr.first;
            vector<int> people = pr.second;
            
            for (int person : people) {
                int idx;
                if (cnt < sz/2)
                    idx = 0;
                else
                    idx = 1;
                
                total += costs[person][idx];
                cnt++;
            }
        }
        
        return total;
    }
};