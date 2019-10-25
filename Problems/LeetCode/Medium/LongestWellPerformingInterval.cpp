// https://leetcode.com/problems/longest-well-performing-interval/

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        // step 1: convert the array to +1/-1
        int n = hours.size();
        for (int i = 0; i < n; i++) {
            if (hours[i] > 8)
                hours[i] = 1;
            else
                hours[i] = -1;
        }
        
        // step 2: count sums[0,i] = sums[i] in separate array
        vector<int> sums(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += hours[i];
            sums[i] = sum;
        }
        
        // step 3: find the desired interval with positive sum
        unordered_map<int,int> hashmap;
        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            if (sums[i] > 0) // interval is [0,i]
                maxLen = i+1;
            
            if (hashmap.find(sums[i]) == hashmap.end())
                hashmap[sums[i]] = i; // map sums[i] to i
            
            if (hashmap.find(sums[i]-1) != hashmap.end()) {
                int j = hashmap[sums[i]-1]; // interval [j-1,i]
                maxLen = max(maxLen, i-j);
            }
        }
        
        return maxLen;
    }
};