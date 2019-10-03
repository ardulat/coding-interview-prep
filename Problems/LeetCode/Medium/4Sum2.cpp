// https://leetcode.com/problems/4sum-ii/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        int res = 0;
        
        unordered_map<int,int> hashmap;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int sum = A[i] + B[j];
                hashmap[sum]++;
            }
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int sum = C[i] + D[j];
                if (hashmap.find(-sum) != hashmap.end())
                    res += hashmap[-sum];
            }
        
        return res;
    }
};