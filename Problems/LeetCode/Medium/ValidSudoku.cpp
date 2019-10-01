// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValid(vector<vector<char>>& board, pair<int,int> a, pair<int,int> b) {
        unordered_set<char> hashset;
        // cout << a.first << " " << a.second << endl;
        // cout << b.first << " " << b.second << ": "<< endl;
        for (int i = a.first; i <= b.first; i++)
            for (int j = a.second; j <= b.second; j++) {
                // cout << i << " " << j << endl;
                if (board[i][j] != '.') {
                    if (hashset.find(board[i][j]) != hashset.end())
                        return false;
                    hashset.insert(board[i][j]);
                }
            }
        
        // cout << "---------------------------------" << endl;
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++)
            if (!isValid(board, {i, 0}, {i, 8}))
                return false;
        
        for (int i = 0; i < board[0].size(); i++)
            if (!isValid(board, {0, i}, {8, i}))
                return false;
        
        for (int i = 0; i < board.size(); i += 3)
            for (int j = 0; j < board[0].size(); j += 3)
                if (!isValid(board, {i, j}, {i+2, j+2}))
                    return false;
        
        return true;
    }
};