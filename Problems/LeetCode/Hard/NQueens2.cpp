// https://leetcode.com/problems/n-queens-ii/

class Solution {
private:
    vector<vector<char>> board;
    int n;

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
    
    int backtrack(int row, int count) {
        for (int col = 0; col < n; col++) {
            // iterate thorugh columns at the current row
            if (isNotUnderAttack(row, col)) {
                // explore this partial candidate solution, and mark the attacking zone
                placeQueen(row, col);
                
                if (row+1 == n) // we reach the bottom, i.e. we find a solution!
                    count++;
                else // we move on to the next row
                    count = backtrack(row+1, count);
                
                // backtrack, i.e. remove the queen and remove the attacking zone
                removeQueen(row, col);
            }
        }
        
        return count;
    }
    
    int totalNQueens(int n) {
        vector<vector<char>> chessboard (n, vector<char>(n, '.'));
        this->board = chessboard;
        this->n = n;
        
        return backtrack(0, 0);
    }
};