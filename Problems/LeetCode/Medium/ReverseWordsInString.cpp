// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    /*
    "the sky is blue"
    "blue is sky the"
    s = "       " -> edge case
    */
    string reverseWords(string s) {
        string res = "";
        int end = s.length()-1;
        
        while (end >= 0) {
            while (end >= 0 && s[end] == ' ') // skip spaces
                end--;
            
            // word end start
            int start = end-1;
            
            while (start >= 0 && s[start] != ' ') // there is a word
                start--;
            
            if (start < -1)
                break;
            
            res += s.substr(start+1, end-start) + " "; // starting index, length
            
            end = start;
        }
        
        res.pop_back(); // remove last space
        
        return res;
    }
};