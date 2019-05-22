// https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution {
public:
    /*
    - store all possible vowels in a hashset
    - if the letter is vowel (is present in the hashset), then reverse it with another such letter
    - use two pointers approach for that
    */
    string reverseVowels(string s) {
        unordered_set<char> vowels({'a','A','e','E','i','I','o','O','u','U'});
        int left = 0, right = s.size()-1; // initialize two pointers
        while (left < right) {
            // case 1: both are not vowels
            if (vowels.find(s[left]) == vowels.end() &&
               vowels.find(s[right]) == vowels.end()) {
                // increment both
                left++;
                right--;
            }
            // case 2: right character is vowel
            else if (vowels.find(s[left]) == vowels.end() &&
                    vowels.find(s[right]) != vowels.end())
                left++;
            // case 3: left character is vowel
            else if (vowels.find(s[left]) != vowels.end() &&
                    vowels.find(s[right]) == vowels.end())
                right--;
            else {
                // swap
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
    }
};