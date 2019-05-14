// https://leetcode.com/problems/minesweeper/

class Solution {
public:
    /*
    'E','E','E',
    'E','E','E',
    'E','M','E'
    
    (x-1,y-1), (x-1,y), (x-1,y+1),
    (x,y-1),   (x,y),   (x,y+1),
    (x+1,y-1), (x+1,y), (x+1,y+1)
    */
    vector<pair<int,int>> getAdjacent(vector<vector<char>>& board, int x, int y) {
        vector<pair<int,int>> res;
        int h = board.size(), w = board[0].size();
        if (x-1 >= 0) {
            if (y-1 >= 0)
                res.push_back(make_pair(x-1,y-1));
            res.push_back(make_pair(x-1,y));
            if (y+1 < w)
                res.push_back(make_pair(x-1,y+1));
        }
        if (y-1 >= 0)
            res.push_back(make_pair(x,y-1));
        if (y+1 < w)
            res.push_back(make_pair(x,y+1));
        if (x+1 < h) {
            if (y-1 >= 0)
                res.push_back(make_pair(x+1,y-1));
            res.push_back(make_pair(x+1,y));
            if (y+1 < w)
                res.push_back(make_pair(x+1,y+1));
        }
        return res;
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
        }
        else if (board[x][y] == 'E') {
            int mines = 0;
            // calculate adjacent mines
            vector<pair<int,int>> adj = getAdjacent(board, x, y);
            
            for (pair<int,int> temp : adj) {
                int xt = temp.first, yt = temp.second;
                if (board[xt][yt] == 'M')
                    mines++;
            }
            
            // change to the number of mines
            if (mines > 0) {
                board[x][y] = mines+'0';
            }
            else {
                board[x][y] = 'B';
                // recursively open other adjacent unrevealed squares
                for (pair<int,int> temp : adj) {
                    // construct vector
                    vector<int> p;
                    p.push_back(temp.first);
                    p.push_back(temp.second);
                    updateBoard(board,p);
                }
            }
        }
        return board;
    }
};