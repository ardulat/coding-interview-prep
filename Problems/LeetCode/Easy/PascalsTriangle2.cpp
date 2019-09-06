// https://leetcode.com/problems/pascals-triangle-ii/submissions/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        
        prev.push_back(1);
        if (rowIndex == 0)
            return prev;
        
        prev.push_back(1);
        if (rowIndex == 1)
            return prev;
        
        for (int i = 2; i <= rowIndex; i++) {
            vector<int> next (i+1, 1); // size i+1, all filled with 1
            
            for (int j = 0; j < prev.size()-1; j++)
                next[j+1] = prev[j]+prev[j+1];
            
            prev = next;
        }
        
        return prev;
    }
};