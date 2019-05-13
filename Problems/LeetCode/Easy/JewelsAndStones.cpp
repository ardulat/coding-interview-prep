// https://leetcode.com/problems/jewels-and-stones/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> hs;
        int count = 0;
        for (int i = 0; i < J.size(); i++)
            hs.insert(J[i]);
        for (int i = 0; i < S.size(); i++)
            if (hs.find(S[i]) != hs.end())
                count++;
        return count;
    }
};