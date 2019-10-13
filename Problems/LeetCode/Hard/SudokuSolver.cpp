// https://leetcode.com/problems/sudoku-solver/

/*
Brute-force: TLE
- using isValidSudoku function from previous similar problem
we can try all possible numbers from the set
*/

class Solution {
private:
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
    
public:
    unordered_set<char> validCandidates(vector<vector<char>>& board, int x, int y) {
        // what are valid candidates for the cell
        unordered_set<char> candidates ({'1','2','3','4','5','6','7','8','9'});
        
        // step 1: check column
        for (int i = 0; i < 9; i++) {
            if (board[i][y] != '.')
                candidates.erase(board[i][y]);
        }
        
        // step 2: check row
        for (int j = 0; j < 9; j++)
            if (board[x][j] != '.')
                candidates.erase(board[x][j]);
        
        // step 3: check sub-box
        int row = (x/3) * 3;
        int col = (y/3) * 3;
        
        for (int i = row; i < row+3; i++)
            for (int j = col; j < col+3; j++)
                if (board[i][j] != '.')
                    candidates.erase(board[i][j]);
        
        return candidates;
    }
    
    bool dfs(vector<vector<char>>& board, int x, int y) {
        if (y >= 9) { // out of bounds
            x++; // next row
            y = 0; // from beginning
        }
        if (x == 9)
            return true;
        
        // cout << x << " " << y << endl;
        
        if (board[x][y] != '.')
            return dfs(board, x, y+1);
        
        // unordered_set<char> temp = validCandidates(board, x, y);
        // set<int> candidates(temp.begin(), temp.end());
        vector<char> candidates {'1','2','3','4','5','6','7','8','9'};
        
        for (char num : candidates) {
            board[x][y] = num;

            if (isValidSudoku(board) && dfs(board, x, y+1))
                return true;
        }
        
        board[x][y] = '.';
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
        
//         if (isValidSudoku(board))
//             cout << "VALID" << endl;
        
//         for (int i = 0; i < 9; i++) {
//             for (int j = 0; j < 9; j++) {
//                 cout << board[i][j] << " ";
//             }
//             cout << endl;
//         }
    }
};



/*
Accepted:
- for each position
- find all valid numbers
- try them
*/

class Solution {
public:
    unordered_set<char> validCandidates(vector<vector<char>>& board, int x, int y) {
        // what are valid candidates for the cell
        unordered_set<char> candidates ({'1','2','3','4','5','6','7','8','9'});
        
        // step 1: check column
        for (int i = 0; i < 9; i++) {
            if (board[i][y] != '.')
                candidates.erase(board[i][y]);
        }
        
        // step 2: check row
        for (int j = 0; j < 9; j++)
            if (board[x][j] != '.')
                candidates.erase(board[x][j]);
        
        // step 3: check sub-box
        int row = (x/3) * 3;
        int col = (y/3) * 3;
        
        for (int i = row; i < row+3; i++)
            for (int j = col; j < col+3; j++)
                if (board[i][j] != '.')
                    candidates.erase(board[i][j]);
        
        return candidates;
    }
    
    bool dfs(vector<vector<char>>& board, int x, int y) {
        if (y >= 9) { // out of bounds
            x++; // next row
            y = 0; // from beginning
        }
        if (x == 9)
            return true;
        
        // cout << x << " " << y << endl;
        
        if (board[x][y] != '.')
            return dfs(board, x, y+1);
        
        unordered_set<char> temp = validCandidates(board, x, y);
        set<int> candidates(temp.begin(), temp.end());
        
        for (char num : candidates) {
            board[x][y] = num;

            if (dfs(board, x, y+1))
                return true;
        }
        
        board[x][y] = '.';
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
        
//         if (isValidSudoku(board))
//             cout << "VALID" << endl;
        
//         for (int i = 0; i < 9; i++) {
//             for (int j = 0; j < 9; j++) {
//                 cout << board[i][j] << " ";
//             }
//             cout << endl;
//         }
    }
};