// https://leetcode.com/problems/contains-duplicate/submissions/

// Algorithm 1: Set
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        
        for (int i = 0; i < nums.size(); i++)
            s.insert(nums[i]);
        
        if (s.size() != nums.size())
            return true;
        return false;
    }
};

// Algorithm 2: HashTable
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> ht;
        
        for (int i = 0; i < nums.size(); i++) {
            if (ht.find(nums[i]) == ht.end())
                ht[nums[i]] = 1;
            else
                return true;
        }
        
        return false;
    }
};