// https://leetcode.com/problems/word-ladder/

typedef pair<string,int> pr;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        
        // construct a set of words
        unordered_set<string> set;
        for (string word : wordList)
            set.insert(word);
        
        // base case:
        if (set.find(endWord) == set.end())
            return 0;
        
        // top-down approach
        queue<pr> q;
        q.push(make_pair(beginWord, 1));
        
        unordered_set<string> visited;
        
        while (!q.empty()) {
            pr p = q.front();
            q.pop();
            
            string temp = p.first;
            int cnt = p.second;
            
            if (temp == endWord)
                return cnt;
            
            if (visited.find(temp) != visited.end()) // skip if visited
                continue;
            
            for (int i = 0; i < temp.length(); i++) {
                string candidate = temp;
                for (char ch : alphabet)
                    if (ch != temp[i]) {
                        candidate[i] = ch;
                        // check if present in words set
                        if (set.find(candidate) != set.end())
                            q.push(make_pair(candidate, cnt+1));
                    }
            }
            
            visited.insert(temp);
        }
        
        return 0;
    }
};