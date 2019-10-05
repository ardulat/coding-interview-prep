// https://leetcode.com/problems/unique-number-of-occurrences/

class Solution {
public:
    /*
    Brute-force: O(N) time, O(N) space
    - count the number of occurences using map
    - put all occurences to the set
    - if already exists, return false
    - otherwise if all are unique, return true
    */
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> hashmap;
        for (int num : arr)
            hashmap[num]++;
        
        unordered_set<int> hashset;
        for (auto pr : hashmap) {
            if (hashset.find(pr.second) != hashset.end())
                return false;
            hashset.insert(pr.second);
        }
        return true;
    }
};