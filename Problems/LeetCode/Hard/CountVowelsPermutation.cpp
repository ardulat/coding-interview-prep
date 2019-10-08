// https://leetcode.com/problems/count-vowels-permutation/

class Solution {
private:
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    
    vector<char> getFollowers(char vowel) {
        vector<char> res;
        if (vowel == 'a')
            res.push_back('e');
        else if (vowel == 'e') {
            res.push_back('a');
            res.push_back('i');
        }
        else if (vowel == 'i') {
            for (char ch : vowels)
                if (ch != 'i')
                    res.push_back(ch);
        }
        else if (vowel == 'o') {
            res.push_back('i');
            res.push_back('u');
        }
        else if (vowel == 'u')
            res.push_back('a');
        
        return res;
    }
    
    unordered_map<int, unordered_map<char, long int>> dp;
    
public:
    int backtrack(int n, char vowel) {
        if (dp.find(n) != dp.end() && dp[n].find(vowel) != dp[n].end()) {
            return dp[n][vowel];
        }
        // base case
        if (n == 1) {
            dp[n][vowel] = 1;
            return dp[n][vowel];
        }
        
        vector<char> followers = getFollowers(vowel);
        int count = 0;
        
        for (char v : followers) {
            dp[n-1][v] = backtrack(n-1, v);
            count += dp[n-1][v];
            // update count by modulo
            count = count % (int) (pow(10.0,9.0) + 7);
        }
        
        dp[n][vowel] = count;
        
        return dp[n][vowel];
    }
    
    int countVowelPermutation(int n) {
        
        for (char ch : vowels)
            dp[n][ch] = backtrack(n, ch);
        
        // for (auto hashmap : dp) {
        //     int key = hashmap.first;
        //     for (auto pr : hashmap.second)
        //         cout << "dp[" << key << "][" << pr.first << "] = " << pr.second << endl;
        // }
        
        // sum all up
        int count = 0;
        for (auto pr : dp[n]) {
            count += pr.second;
            // update count by modulo
            count = count % (int) (pow(10.0,9.0) + 7);
        }
        
        return count;
    }
};