// https://leetcode.com/problems/word-search/

class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, int idx, string& word) {
        if (idx >= word.length())
            return true;
        
        if (i >= 0 && i < board.size() && j >= 0 && j < board[i].size()) {
            // check only in case path is a substring of word
            if (board[i][j] != word[idx])
                return false;
            
            board[i][j] = '*';
            
            if (dfs(board, i-1, j, idx+1, word) ||
                dfs(board, i+1, j, idx+1, word) ||
                dfs(board, i, j-1, idx+1, word) ||
                dfs(board, i, j+1, idx+1, word))
                return true;
            
            board[i][j] = word[idx];
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if (n == 0)
            return false;
        int m = board[0].size();
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (dfs(board, i, j, 0, word))
                    return true;
            }
        
        return false;
    }
};