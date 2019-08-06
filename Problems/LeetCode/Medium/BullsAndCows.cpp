// https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> table;
        for (char ch : secret)
            table[ch]++;
        
        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                table[guess[i]]--;
            }
        }
        
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] != guess[i] && table[guess[i]]) {
                cout << i << " " << guess[i] << endl;
                cows++;
                table[guess[i]]--;
            }
        }
        
        // construct a resultant string
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};