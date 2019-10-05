// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/

class Solution {
public:
    /*
    Brute-force:
    - do the recursive process until there is nothing to delete (base case)
    - at each recursive call, find such k length substring consisting of the same letters
    - remove them or add the string without those k length substrings
    - call the function again to the resultant string
    */
    bool isDuplicate(string str, int k) {
        char ch = str[0]; // sample character
        
        for (int i = 1; i < k; i++) {
            if (ch != str[i])
                return false; // distinct character
        }
        
        return true;
    }
    
    string removeDuplicates(string s, int k) {
        string res = "", cur = "";
        int i = 0, n = s.length();
        
        while (i < n) {
            if (cur.empty()) {
                // construct first window
                for (int j = 0; j < k; j++) {
                    if (i < n)
                        cur += s[i];
                    else {
                        res += cur;
                        break;
                    }
                    i++;
                }
                i--; // bug
            }
            else
                cur += s[i];
            
            if (cur.length() == k && !isDuplicate(cur, k)) {
                res += s[i-k+1]; // 'd'
                cur.erase(0, 1); // remove the first character - O(N) worst?
            } else
                cur = "";
            
            i++;
        }
        // add last k-1 characters
        i = i-k+1;
        while (!cur.empty() && i < n) {
            res += s[i];
            i++;
        }
        
        if (s == res) // no changes = no duplicates
            return s;
        
        return removeDuplicates(res, k);
    }
};