// https://leetcode.com/problems/word-search-ii/

class Solution {
private:
    struct TrieNode {
        unordered_map<char,TrieNode*> children;
        string word;
        
        TrieNode() {}
    };
    
    void insert(TrieNode *root, string word) {
        TrieNode *temp = root;
        
        for (char ch : word) {
            if (temp->children.find(ch) == temp->children.end())
                temp->children[ch] = new TrieNode();
            
            temp = temp->children[ch];
        }
        
        temp->word = word;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode *parent, vector<string>& res) {
        if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size()) {
            // cout << ch << endl;
            
            TrieNode *temp = parent;
            // there is no such prefix/word
            if (temp->children.find(ch) == temp->children.end())
                return;
            
            temp = temp->children[ch];
            
            if (!temp->word.empty()) {
                res.push_back(temp->word);
                temp->word = "";
            }
            
            board[i][j] = '#'; // remove for now as visited
            
            // otherwise, construct word further
            dfs(board, i-1, j, temp, res);
            dfs(board, i+1, j, temp, res);
            dfs(board, i, j-1, temp, res);
            dfs(board, i, j+1, temp, res);
            
            if (temp->children.empty()) // leaf node
                parent->children.erase(ch);
            
            // bring the character back to board
            board[i][j] = ch;
            cout << board[i][j] << endl;
        }
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        
        // step 1: construct a Trie of words
        TrieNode *root = new TrieNode();
        
        for (string word : words)
            insert(root, word);
        
        // step 2: dfs from each node in the graph
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                dfs(board, i, j, root, res);
        
        return res;
    }
};