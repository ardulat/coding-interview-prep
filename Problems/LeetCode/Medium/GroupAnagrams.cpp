// https://leetcode.com/problems/group-anagrams/

// Approach: utilize hashmap, but sort each string before inserting

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> hashmap;
        
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i]; // copy constructor
            sort(s.begin(), s.end());
            hashmap[s].push_back(strs[i]);
        }
        
        for (auto& x : hashmap) {
            vector<string> groupStrings = x.second;
            result.push_back(groupStrings);
        }
        
        return result;
    }
};