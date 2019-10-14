// https://leetcode.com/problems/sort-an-array/submissions/

class Solution {
public:
    vector<int> merge(vector<int>& left, vector<int>& right) {
        int n = left.size(), m = right.size();
        vector<int> res(n+m);
        
        int l = 0, r = 0;
        int idx = 0;
        
        while (l < n && r < m) {
            if (left[l] < right[r]) {
                res[idx] = left[l];
                l++;
            }
            else {
                res[idx] = right[r];
                r++;
            }
            idx++;
        }
        
        while (l < n || r < m) {
            if (l < n) {
                res[idx] = left[l];
                l++;
            }
            if (r < m) {
                res[idx] = right[r];
                r++;
            }
            idx++;
        }
        
        return res;
    }
    
    void mergeSort(vector<int>& nums) {
        vector<vector<int>> subs;
        
        for (int i = 0; i < nums.size(); i++)
            subs.push_back( vector<int>{nums[i]} );
        
        while (subs.size() > 1) {
            vector<vector<int>> res;
            int idx = 0;
            while (idx < subs.size()) {
                vector<int> r = idx != subs.size()-1 ? merge(subs[idx], subs[idx+1]) : subs[idx];
                
                res.push_back(r);
                idx += 2;
            }
            
            subs = res;
        }
        
        nums = subs[0];
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums);
        return nums;
    }
};