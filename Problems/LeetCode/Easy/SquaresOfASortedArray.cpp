// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    /*
    - find the index of the first non-negative number
    - start iterating  over positive and negative numbers (two pointers)
    - at each step compare those two
    */
    vector<int> sortedSquares(vector<int>& A) {
        int pos = 0;
        while (pos < A.size() && A[pos] < 0)
            pos++;
        int neg = pos-1;
        vector<int> squares;
        while (neg > -1 && pos < A.size()) {
            if (abs(A[neg]) < abs(A[pos])) {
                squares.push_back(A[neg]*A[neg]);
                neg--;
            } else {
                squares.push_back(A[pos]*A[pos]);
                pos++;
            }
        }
        while (neg > -1) {
            squares.push_back(A[neg]*A[neg]);
            neg--;
        }
        while (pos < A.size()) {
            squares.push_back(A[pos]*A[pos]);
            pos++;
        }
        return squares;
    }
};