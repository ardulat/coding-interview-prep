// https://leetcode.com/problems/group-anagrams/

// Approach: utilize hashmap, but sort each string before inserting

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<int>> hashmap;
        
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i]; // copy constructor
            sort(s.begin(), s.end());
            hashmap[s].push_back(i);
        }
        
        for (auto& x : hashmap) {
            vector<int> groupIndexes = x.second;
            vector<string> groupStrings;
            for (int index : groupIndexes)
                groupStrings.push_back(strs[index]);
            result.push_back(groupStrings);
        }
        
        return result;
    }
};