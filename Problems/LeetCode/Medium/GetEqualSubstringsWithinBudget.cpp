// https://leetcode.com/problems/get-equal-substrings-within-budget/

class Solution {
public:
    /*
    Brute-force: O(N) time, O(1) space
    - substring: sliding window approach
    */
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length(); // = t.length();
        
        int left = 0, right = 0;
        int maxLen = 0;
        while (right < n) {
            maxCost -= abs(s[right]-t[right]);
            
            if (maxCost < 0) {
                // cout << s.substr(left, right+1-left) << endl;
                maxLen = max(maxLen, right+1-left);
                maxCost += abs(s[left]-t[left]);
                left++;
            }
            
            right++;
        }
        
        return right-left;
    }
};