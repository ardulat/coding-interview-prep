// https://leetcode.com/problems/find-all-anagrams-in-a-string

// Brute-force:
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len = s.size(), anagramLen = p.size();
        unordered_map<string, vector<int>> hashmap;
        string sub = s.substr(0, anagramLen);
        // consider all substrings
        for (int index = 0; index < len-anagramLen+1; index++) {
            // sort the substr
            sort(sub.begin(), sub.end());
            // insert to hashtable <string, indices> pair
            hashmap[sub].push_back(index);
            
            // sliding window
            sub += s[index+anagramLen];
            sub.erase(0, 1);
        }
        
        sort(p.begin(), p.end());
        
        return hashmap[p];
    }
};

// Approach: 1. use hashtable to store occurences in anagram
//           2. track difference (of chars) by incrementing/decrementing variable
//           3. if they are not different, add start element
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len = s.size(), anagramLen = p.size();
        vector<int> result;
        
        unordered_map<char, int> hashmap;
        
        for (int i = 0; i < anagramLen; i++)
            hashmap[p[i]]++;
        
        int start = 0, end = 0, diff = anagramLen;
        for (end = 0; end < anagramLen; end++) {
            hashmap[s[end]]--;
            if (hashmap[s[end]] >= 0) // was part of anagram
                diff--;
        }
        if (diff == 0)
            result.push_back(start);
        
        while (end < len) {
            if (hashmap[s[start]] >= 0) // if was part of anagram
                diff++;
            hashmap[s[start]]++; // remove first
            
            hashmap[s[end]]--; // add last
            if (hashmap[s[end]] >= 0) // if part of anagram
                diff--;
            
            start++;
            end++;
            if (diff == 0)
                result.push_back(start);
        }
            
        return result;
    }
};