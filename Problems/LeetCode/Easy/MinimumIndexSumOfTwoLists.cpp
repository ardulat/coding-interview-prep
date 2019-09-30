// https://leetcode.com/problems/minimum-index-sum-of-two-lists/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string, int> andy;
        unordered_map<string, int> doris;
        
        // step 1: construct maps
        for (int i = 0; i < list1.size(); i++)
            andy[list1[i]] = i;
        
        for (int i = 0; i < list2.size(); i++)
            doris[list2[i]] = i;
        
        // step 2: find min index sum
        int min_sum = INT_MAX;
        for (auto pr : andy) {
            string restr = pr.first;
            int idx = pr.second;
            
            if (doris.count(restr) > 0) {
                idx += doris[restr];
                min_sum = min(min_sum, idx);
            }
        }
        
        // step 3: add results with min sum
        for (auto pr : andy) {
            string restr = pr.first;
            int idx = pr.second;
            
            if (doris.count(restr) > 0 && idx + doris[restr] == min_sum)
                res.push_back(restr);
        }
        
        return res;
    }
};