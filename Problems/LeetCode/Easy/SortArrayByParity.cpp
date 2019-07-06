// https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    /*
    Algorithm 1:
    - count number of evens and odds (one extra traversal)
    - use two pointers then
    
    Algorithm 2:
    - use two arrays consisting of odds and evens (memory)
    - concatenate them at the end
    
    Algorithm 1:
    - start adding evens from the beginning of the new array
    - add odds from the last element (one traversal only)
    */
    vector<int> sortArrayByParity(vector<int>& A) {
        int left = 0, right = A.size()-1;
        vector<int> res(A.size());
        
        for (int num : A) {
            if (num % 2 == 1) { // odd
                res[right] = num;
                right--;
            } else { // even
                res[left] = num;
                left++;
            }
        }
        
        return res;
    }
};