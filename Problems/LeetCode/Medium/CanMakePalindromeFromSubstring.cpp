// https://leetcode.com/problems/can-make-palindrome-from-substring/

// Brute-force: TLE
class Solution {
public:
    bool query(string& s, int left, int right, int k) {
        // first idea: two pointers from left and right and count pairs that are not equal
        // bced - 4 unique
        // second idea: because we can rearrange, track the number of unique characters without pairs
        unordered_map<int,int> hashmap;
        
        for (int i = left; i <= right; i++)
            hashmap[s[i]]++;
        
        int count = 0;
        for (auto pr : hashmap) {
            if (pr.second % 2 != 0)
                count++;
            
            if (count/2 > k)
                return false;
        }
        
        return true;
    }
    
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool> res;
        
        for (vector<int> q : queries)
            res.push_back(query(s, q[0], q[1], q[2]));
        
        return res;
    }
};

// Preprocess all prefixes (vector)
class Solution {
public:
    bool query(string& s, int left, int right, int k, vector<vector<int>>& prefixes) {
        
        vector<int> first = prefixes[left];
        vector<int> second = prefixes[right+1];
        
        int odds = 0;
        for (int i = 0; i < 26; i++) { // O(26)
            // take out frequency from first
            second[i] -= first[i];
            
            if (second[i] % 2 != 0)
                odds++;
            
            if (odds/2 > k)
                return false;
        }
        
        return true;
    }
    
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool> res(n, false);
        
        // preprocess all prefixes and store all frequencies
        vector<vector<int>> prefixes;
        vector<int> cur(26, 0);
        prefixes.push_back(cur); // empty hashmap
        for (char ch : s) {
            cur[ch-'a']++;
            prefixes.push_back(cur);
        }
        
        for (int i = 0; i < n; i++) {
            vector<int> q = queries[i];
            res[i] = query(s, q[0], q[1], q[2], prefixes);
        }
        
        return res;
    }
};