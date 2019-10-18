// https://leetcode.com/problems/permutations/

class Solution {
public:
    /*
    Backtracking:
    - for each position we have N possible digits to place
    - place each character and reduce N for the next recursion call
    - if reached the desired size, stop
    */
    vector<bool> placed;
    vector<vector<int>> res;
    
    bool canPlaceNumber(int pos) {
        return placed[pos] == false;
    }
    
    void place(vector<int>& cur, vector<int>& nums, int i) {
        placed[i] = true;
        cur.push_back(nums[i]);
    }
    
    void remove(vector<int>& cur, int i) {
        placed[i] = false;
        cur.pop_back();
    }
    
    void backtrack(vector<int>& nums, vector<int> cur) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (canPlaceNumber(i)) {
                
                place(cur, nums, i);
                
                backtrack(nums, cur);
                
                remove(cur, i);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        this->placed = vector<bool>(nums.size(), false);
        this->res = vector<vector<int>>();
        
        backtrack(nums, vector<int>());
        
        return res;
    }
};