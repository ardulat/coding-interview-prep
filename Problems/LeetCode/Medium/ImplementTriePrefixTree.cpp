// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
private:
    struct TrieNode {
        unordered_map<char,TrieNode*> children; // hashmap for children
        bool isWord; // flag for representing the words
    };
    
    TrieNode *root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *temp = root;
        
        for (char ch : word) {
            if (temp->children.find(ch) == temp->children.end())
                temp->children[ch] = new TrieNode();
            
            temp = temp->children[ch];
        }
        
        temp->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *temp = root;
        
        for (char ch : word) {
            if (temp->children.find(ch) == temp->children.end())
                return false;
            
            temp = temp->children[ch];
        }
        
        return temp->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *temp = root;
        
        for (char ch : prefix) {
            if (temp->children.find(ch) == temp->children.end())
                return false;
            
            temp = temp->children[ch];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */