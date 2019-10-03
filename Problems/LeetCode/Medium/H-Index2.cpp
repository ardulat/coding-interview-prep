// https://leetcode.com/problems/h-index-ii/submissions/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        
        int n = citations.size();
        int left = 0, right = n;
        int res = 0;
        while (left <= right) {
            int mid = (left+right)/2;
            
            if (mid >= n)
                break;
            
            if (citations[mid] >= n-mid) {
                res = n-mid;
                right = mid-1;
            }
            else
                left = mid+1;
        }
        
        return res;
    }
};