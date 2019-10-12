// https://leetcode.com/problems/maximum-number-of-balloons/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<char> balloon {'b', 'a', 'l', 'l', 'o', 'o', 'n'};
        
        unordered_map<char,int> hashmap;
        for (char ch : text)
            hashmap[ch]++;
        
        int count = 0;
        while (true) {
            
            for (char ch : balloon) {
                if (hashmap[ch] == 0)
                    return count;

                hashmap[ch]--;
            }
            count++;
        }
        
        return count;
    }
};