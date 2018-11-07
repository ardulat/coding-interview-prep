// https://leetcode.com/problems/count-and-say/

// Approach:
// 1. to count nth term, recur and count (n-1)th term
//    with the base case equal to "1" when N = 1
// 2. iterate through previous result, and count all
//    the occurrences of the ith term
// 3. to count occurences, use simple counter until
//    you find not equal characters

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        
        string prev = countAndSay(n-1);
        int len = prev.size();
        string res = "";
        char current = prev[0];
        int count = 1;
        int i = 1;
        
        while (i <= len) {
            if (prev[i] == current && i != len)
                count++;
            else {
                res += count + '0';
                res += current;
                // update states
                current = prev[i];
                count = 1;
            }
            i++;
        }
        
        return res;
    }
};