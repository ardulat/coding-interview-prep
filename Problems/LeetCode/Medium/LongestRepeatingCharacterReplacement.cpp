// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    /*
    "BABAB"
    {A: 2, B: 3}
    "AABBBABBA"
    
    Brute-force:
    - consider all substrings [i,j] where i <= j
    - count the occurrence of characters in the substring
    - track the most frequent character with its frequency
    
    - based on the data, evaluate if substring satisfies the constraint
    - constraint: min number of changes to the string <= k
    
    - increase (increment end) the window until constraint is satisfied
    - if not, decrease (increment start) the window until constraint is satisfied
    */
    int characterReplacement(string s, int k) {
        // base case for empty string
        if (s.empty())
            return 0;
        
        unordered_map<char,int> window;
        
        int start = 0, end = 0;
        int n = s.length();
        int maxFreq = 1, len = 0;
        int maxLen = 1;
        window[s[0]]++; // starting window
        
        while (start < n) {
            // cout << s.substr(start, len+1) << endl;
            // cout << "len = " << len+1 << " maxFreq = " << maxFreq << endl;
            // cout << "----------------------" << endl;
            if (len+1 - maxFreq <= k && len+1 <= n) { // what if we increase our window?
                len++;
                maxLen = max(maxLen, len); // 4
                
                if (end < n-1) {
                    // increase window
                    end++;
                    char cur = s[end]; // B
                    
                    window[cur]++; // 2
                    

                    maxFreq = max(maxFreq, window[cur]); // 3
                }
            }
            else { // BABB
                // decrease window
                char cur = s[start]; // A
                window[cur]--; // 1
                len--; // 3
                start++;
                
                if (maxFreq == window[start]+1) { // update maxFreq
                    for (auto pr : window) // O(26)
                        maxFreq = max(maxFreq, pr.second); // 2
                }
            }
        }
        
        return maxLen;
    }
};