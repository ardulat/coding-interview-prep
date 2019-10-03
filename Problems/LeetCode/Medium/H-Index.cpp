// https://leetcode.com/problems/h-index/

class Solution {
public:
    /*
    [0,0,0,0,1,1,2,3,3,5,6]
    [0,1,3,5,6]
    
    Brute-force: O(NlogN)
    - sort the array in descending order
    - N-i = h => N-h = i
    */
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        
        int n = citations.size();
        int start = 0;
        for (int i = 0; i < n; i++)
            if (citations[i] >= n-i)
                return n-i;
        
        return 0;
    }
};