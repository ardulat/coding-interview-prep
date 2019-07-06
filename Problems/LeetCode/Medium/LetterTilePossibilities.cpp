// https://leetcode.com/problems/letter-tile-possibilities/

class Solution {
public:
    /*
    - build a map of the existing letters
    - either put at each position or don't put any of the letters
    - push to the hashset
    - recur to the next word
    - stop when the number of characters inserted equals len of the original
    */
    void generateSequences(string cur, unordered_map<char,int> ht, unordered_set<string>& res, int maxLen) {
        if (cur.size() < maxLen)
            for (auto pr : ht)
                if (pr.second > 0) {
                    string temp = cur + pr.first;
                    res.insert(temp);
                    ht[pr.first]--;
                    generateSequences(temp, ht, res, maxLen);
                    ht[pr.first]++;
                }
    }
    
    int numTilePossibilities(string tiles) {
        unordered_map<char,int> ht;
        for (char ch : tiles)
            ht[ch]++;
        
        unordered_set<string> res;
        generateSequences("", ht, res, tiles.size());
        
        return res.size();
    }
};