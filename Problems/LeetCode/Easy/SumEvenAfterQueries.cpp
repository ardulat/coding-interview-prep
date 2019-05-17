// https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> result;
        // sum evens
        int sumEven = 0;
        for (int num : A)
            if (num % 2 == 0)
                sumEven += num;
        for (vector<int> query : queries) {
            int val = query[0], index = query[1];
            if (A[index] % 2 == 0) // is in the previous sumEven
                sumEven -= A[index];
            A[index] += val; // modify the array
            if (A[index] % 2 == 0) // is in the next sumEven
                sumEven += A[index];
            result.push_back(sumEven);
        }
        return result;
    }
};