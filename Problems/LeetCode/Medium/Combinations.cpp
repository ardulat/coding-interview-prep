// https://leetcode.com/problems/combinations/

class Solution {
private:
    vector<vector<int>> res;
    int k;
    int n;
    
public:
    void place(vector<int>& cur, int i) {
        cur.push_back(i);
    }
    
    void remove(vector<int>& cur, int i) {
        cur.pop_back();
    }
    
    void backtrack(vector<int> cur, int pos) {
        if (cur.size() == k) { // we have reached filling k positions
            res.push_back(cur);
            return;
        }
        
        for (int i = pos; i <= n; i++) {
            place(cur, i);

            backtrack(cur, i+1);

            remove(cur, i);
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        this->res = vector<vector<int>>();
        this->k = k;
        this->n = n;
        
        backtrack(vector<int>(), 1);
        
        return res;
    }
};