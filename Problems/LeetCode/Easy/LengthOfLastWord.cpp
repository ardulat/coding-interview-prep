// https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int ptr = s.size()-1; // start from the end
        bool hasStarted = false; // counting/traversing the word
        while (ptr > -1) { // in bounds
            if (s[ptr] != ' ') {
                if (!hasStarted) // have not started traversing the word yet
                    hasStarted = true;
                ans++;
            } else
                if (hasStarted) // find space after the word traversal
                    break;
            ptr--;
        }
        
        return ans;
    }
};