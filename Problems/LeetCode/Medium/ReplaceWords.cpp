// https://leetcode.com/problems/replace-words/

class Solution {
private:
    struct TrieNode {
        unordered_map<char,TrieNode*> children;
        bool isWord;
    };

    TrieNode *root;
    
    void insert(TrieNode *root, string word) {
        TrieNode *temp = root;
        
        for (char ch : word) {
            if (temp->children.find(ch) == temp->children.end())
                temp->children[ch] = new TrieNode();
            
            temp = temp->children[ch];
        }
        
        temp->isWord = true;
    }
    
    string replace(TrieNode *root, string word) {
        TrieNode *temp = root;
        string res = "";
        
        for (char ch : word) {
            if (temp->children.find(ch) == temp->children.end())
                return word; // there is no such word in dict
            
            res += ch;
            temp = temp->children[ch]; // next node
            
            if (temp->isWord)
                break;
        }
        
        return res;
    }
    
public:
    string replaceWords(vector<string>& dict, string sentence) {
        root = new TrieNode();
        
        for (string word : dict)
            insert(root, word);
        
        string res = "";
        string word = "";
        int i = 0;
        while (i <= sentence.length()) {
            if (i < sentence.length() && sentence[i] != ' ')
                word += sentence[i];
            else {
                string replaced = replace(root, word);
                res += replaced + " ";
                word = "";
            }
            
            i++;
        }
        
        // remove last space
        res.pop_back();
        
        return res;
    }
};