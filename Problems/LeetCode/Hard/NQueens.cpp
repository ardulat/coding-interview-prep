// https://leetcode.com/problems/n-queens/

class Solution {
private:
    vector<string> board;
    int n;
    vector<vector<string>> res;
    
public:
    bool isNotUnderAttack(int row, int col) {
        // check if row is not under attack
        for (int i = 0; i < n; i++)
            if (board[row][i] == 'Q')
                return false;
        
        // check if col is not under attack
        for (int i = 0; i < n; i++)
            if (board[i][col] == 'Q')
                return false;
        
        // check if "dale" diagonal is not under attack
        int i = row, j = col;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }
        i = row, j = col;
        while (i < n && j < n) {
            if (board[i][j] == 'Q')
                return false;
            i++;
            j++;
        }
        
        // check if "hill" diagonal is not under attack
        i = row, j = col;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q')
                return false;
            i--; // move top
            j++; // move right
        }
        i = row, j = col;
        while (i < n && j >= 0) {
            if (board[i][j] == 'Q')
                return false;
            i++; // move bottom
            j--; // move left
        }
        
        return true;
    }
    
    void placeQueen(int row, int col) {
        board[row][col] = 'Q';
    }
    
    void removeQueen(int row, int col) {
        board[row][col] = '.';
    }
    
    void printBoard() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
    
    void backtrack(int row) {
        for (int col = 0; col < n; col++) {
            if (isNotUnderAttack(row, col)) {
                placeQueen(row, col);
                
                if (row+1 == n) { // solution found!
                    // printBoard();
                    res.push_back(board);
                }
                else
                    backtrack(row+1);
                
                removeQueen(row, col);
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        this->board = vector<string>(n);
        this->n = n;
        
        // initialize board
        string row = "";
        for (int i = 0; i < n; i++)
            row += '.';
        
        for (int i = 0; i < n; i++)
            this->board[i] = row;
        
        this->res = vector<vector<string>>();
        
        backtrack(0);
        
        return res;
    }
};