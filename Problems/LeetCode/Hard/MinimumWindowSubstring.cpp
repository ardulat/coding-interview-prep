// https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    bool isPerfect(unordered_map<char,int>& hashmap) { // O(26) 26 uniques
        for (auto pr : hashmap)
            if (pr.second > 0)
                return false;
        return true;
    }
    
    string minWindow(string s, string t) {
        // step 1: add all occurrences of characters from string T to hashmap
        unordered_map<char,int> hashmap;
        for (char ch : t)
            hashmap[ch]++;
        
        // step 2: initiate the sliding window with two pointers to track characters in a given substring
        int left = 0, right = 0;
        int n = s.length();
        int runningMin = n; // max possible is whole string
        
        // remember params for substring function to generate the result
        int start = n;
        
        while (left < n && right < n) {
            
            if (right != n)
                if (hashmap.find(s[right]) != hashmap.end()) {
                    hashmap[s[right]]--;
                }

            while (left < n && isPerfect(hashmap)) { // increase left
                if (right-left+1 <= runningMin) { // update
                    runningMin = right-left+1;
                    start = left;
                }
                
                if (hashmap.find(s[left]) != hashmap.end())
                    hashmap[s[left]]++;
                
                left++;
            }
            
            right++;
        }
        
        return s.substr(start, runningMin);
    }
};