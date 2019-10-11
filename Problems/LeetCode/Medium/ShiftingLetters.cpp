// https://leetcode.com/problems/shifting-letters/

class Solution {
public:
    /*
    Brute-force: O(n^2)
    - iterate over shifts array and implement shifting for i+1 elements
    - there are two for loops
    
    Optimization: O(n)
    - preprocess shifts array by summing from right/end of array
    - for [3,5,9] case we will then have the following: [17,14,9]
    - we will shift each character only once instead of n times (one loop)
    
    edge case:
    - big numbers in shifts array
    
    solution:
    - store modulus 26?
    */
    char shiftBy(char ch, int shifts) {
        int num = ch-'a';
        int shifted = (num + shifts) % 26; // 26 lowercase characters
        char res = shifted+'a';
        
        return res;
    }
    
    string shiftingLetters(string S, vector<int>& shifts) {
        // step 1: preprocess shifts array
        int n = shifts.size(); // = S.length()
        int sum = 0;
        for (int i = n-1; i >= 0; i--) {
            shifts[i] = (sum % 26 + shifts[i] % 26) % 26; // 14 + 3 = 17
            sum = shifts[i]; // 14 + 3 = 17
        }
        
        // step 2: shift characters
        for (int i = 0; i < n; i++) {
            S[i] = shiftBy(S[i], shifts[i]);
        }
        
        return S;
    }
};