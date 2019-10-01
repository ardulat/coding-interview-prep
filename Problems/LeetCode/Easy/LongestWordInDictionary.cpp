// https://leetcode.com/problems/longest-word-in-dictionary/

class Solution {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isWord;
        int len;
        string word;
        
        TrieNode() : isWord(false) {}
    };
    
    void insert(TrieNode *temp, string word) {
        for (char ch : word) {
            if (temp->children.find(ch) == temp->children.end())
                temp->children[ch] = new TrieNode();
            
            temp = temp->children[ch];
        }
        
        temp->isWord = true;
        temp->len = word.length();
        temp->word = word;
    }
    
    void traverse(TrieNode *temp, string& res) {
        if (!temp->isWord)
            return;
        // cout << temp->word << endl;
        if (temp->len > res.length())
            res = temp->word;
        else if (temp->len == res.length() && temp->word.compare(res) < 0)
            res = temp->word;
        
        for (auto pr : temp->children)
            // cout << temp->word << " + " << pr.first << endl;
            traverse(temp->children[pr.first], res);
    }
    
public:
    string longestWord(vector<string>& words) {
        TrieNode *root = new TrieNode();
        root->isWord = true;
        for (string word : words)
            insert(root, word);
        
        string res = "";
        traverse(root, res);
        
        return res;
    }
};