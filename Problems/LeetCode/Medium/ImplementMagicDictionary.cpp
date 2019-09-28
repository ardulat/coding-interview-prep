// https://leetcode.com/problems/implement-magic-dictionary/

class MagicDictionary {
private:
    unordered_set<string> words;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string word : dict)
            words.insert(word);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (int k = 0; k < word.length(); k++) {
            char ch = word[k];
            for (int i = 0; i < 26; i++) {
                char alph = 'a'+i;
                if (alph != ch) {
                    word[k] = alph;
                    if (words.find(word) != words.end())
                        return true;
                }
            }
            // backtracking
            word[k] = ch;
        }
        
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */