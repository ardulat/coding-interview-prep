// https://leetcode.com/problems/valid-palindrome-ii/

class Solution {
public:
    bool isPalindrome(string& str, int left, int right) {
        while (left <= right) {
            char leftChar = str[left];
            char rightChar = str[right];
            if (leftChar == rightChar) {
                left++;
                right--;
            } else
                return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while (left <= right) {
            if (s[left] != s[right])
                return isPalindrome(s, left+1, right) ||
                isPalindrome(s, left, right-1);
            left++;
            right--;
        }
        return true;
    }
};