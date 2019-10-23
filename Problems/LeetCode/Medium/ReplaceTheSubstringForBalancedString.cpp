// https://leetcode.com/problems/replace-the-substring-for-balanced-string/

class Solution {
public:
    bool isPerfect(unordered_map<char,int>& hashmap) { // O(4)
        for (auto pr : hashmap)
            if (pr.second > 0)
                return false;
        return true;
    }
    
    int balancedString(string s) {
        // step 1: count the number of occurrences in s
        unordered_map<char,int> hashmap;
        for (char ch : s)
            hashmap[ch]++;
        
        // step 2: count the number of required, and update hashmap
        int n = s.length();
        int required = n/4; // balanced
        bool isBalanced = true;
        
        for (auto pr : hashmap) {
            char ch = pr.first;
            int freq = pr.second;
            hashmap[ch] = max(0, freq-required);
            
            if (hashmap[ch] != 0)
                isBalanced = false;
        }
        
        // step 3: check if already balanced
        if (isBalanced)
            return 0;
        
        // step 4: reduce the problem to minimum window substring
        int start = 0, end = 0;
        int runningMin = n; // max possible length
        
        while (end < n) {
            if (hashmap.find(s[end]) != hashmap.end())
                hashmap[s[end]]--; // add to window
            
            while (isPerfect(hashmap)) {
                if (hashmap.find(s[start]) != hashmap.end())
                    hashmap[s[start]]++; // remove from window
                
                runningMin = min(runningMin, end-start+1); // update
                
                start++;
            }
            
            end++;
        }
        
        return runningMin;
    }
};