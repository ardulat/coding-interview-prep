// https://leetcode.com/problems/relative-sort-array/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> hashmap;
        for (int num : arr1) hashmap[num]++;
        int idx = 0;
        for (int num : arr2)
            while (hashmap[num]) {
                arr1[idx] = num;
                idx++;
                hashmap[num]--;
            }
        for (auto pr : hashmap)
            if (pr.second)
                while (hashmap[pr.first]) {
                    arr1[idx] = pr.first;
                    idx++;
                    hashmap[pr.first]--;
                }
        return arr1;
    }
};