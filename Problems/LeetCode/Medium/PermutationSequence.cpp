// https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    int factorial(int n) 
    {
        // single line to find factorial 
        return (n==1 || n==0) ? 1: n * factorial(n - 1);  
    }
    
    string getPermutation(int n, int k, string& alphabet) {
        if (n == 1)
            return alphabet; // of size 1
        
        int idx = (k-1) / factorial(n-1); // idx = 1
        char num = alphabet[idx]; // 2 => "13"
        
        alphabet.erase(alphabet.begin()+idx); // remove used number
        k = k - idx * factorial(n-1); // 
        
        return num + getPermutation(n-1, k, alphabet);
    }
    
    string getPermutation(int n, int k) {
        string alphabet = "";
        for (int i = 1; i <= n; i++)
            alphabet += i+'0';
        
        return getPermutation(n, k, alphabet);
    }
};