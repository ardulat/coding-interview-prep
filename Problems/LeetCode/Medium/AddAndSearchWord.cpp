// https://leetcode.com/problems/add-and-search-word-data-structure-design/

class WordDictionary {
private:
    struct TrieNode {
        unordered_map<char,TrieNode*> children;
        bool isWord;
    };
    
    TrieNode *root;
    
    bool dfs(TrieNode *temp, string word) {
        // cout << word << endl;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            
            if (ch == '.') {
                bool res = false;
                // any character
                for (auto p : temp->children) {
                    res = dfs(temp, p.first + word.substr(i+1));
                    if (res)
                        return true;
                }
                
                return res;
            }
            else {
                if (temp->children.find(ch) == temp->children.end())
                    return false;
                
                temp = temp->children[ch];
            }
        }
        
        return temp->isWord;
    }
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *temp = root;
        for (char ch : word) {
            if (temp->children.find(ch) == temp->children.end())
                temp->children[ch] = new TrieNode();
            
            temp = temp->children[ch];
        }
        
        temp->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        
        return dfs(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */