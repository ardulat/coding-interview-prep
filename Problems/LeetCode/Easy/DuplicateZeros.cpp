// https://leetcode.com/problems/duplicate-zeros/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                int temp = 0;
                
                for (int j = i+1; j < n; j++) {
                    // cout << "swapping elements: " << endl;
                    // cout << temp << " " << arr[j] << endl;
                    swap(temp, arr[j]);
                    // cout << temp << " " << arr[j] << endl;
                    // cout << "-----------------" << endl;
                }
                i++; // skip zero
            }
        }
    }
};

/*
Brute-force:
- note: the size remains the same
- thus, put 0 at next position, shift all the remaining
- worst case time: O(N^2)
*/