// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

// Backtracking: TLE
class Solution {
public:
    bool evaluate(unordered_map<int,int>& a, unordered_map<int,int>& b) {
        int uniques = 0;
        
        for (auto pr : a) {
            if (pr.second > 0)
                uniques++;
            if (uniques > 1)
                break; // try another map
        }
        
        if (uniques == 1)
            return true;
        
        uniques = 0;
        
        for (auto pr : b) {
            if (pr.second > 0)
                uniques++;
            if (uniques > 1)
                return false;
        }
        
        return uniques == 1;
    }
    
    bool evaluate(unordered_set<int> hashset, int num) {
        hashset.insert(num);
        
        return hashset.size() <= 1;
    }
    
    int backtrack(vector<int>& A, vector<int>& B, unordered_set<int> a, unordered_set<int> b, int pos, int cost) {
        
        if (pos >= A.size()) {
        //     cout << "a: ";
        // for (auto pr : a)
        //     cout << "{" << pr.first << ", " << pr.second << "}" << " ";
        // cout << endl;
        // cout << "b: ";
        // for (auto pr : b)
        //     cout << "{" << pr.first << ", " << pr.second << "}" << " ";
        // cout << endl;
        // cout << "------------------------------------" << endl;
            return cost;
        }
        
        // if (pos != 0) { // evaluate previous operation
        //     a.insert(A[pos-1]);
        //     b.insert(B[pos-1]);
        // }
        
        // option 1: leave the numbers at the position
        int leave;
        
        // a[A[pos]]++; // 1: 1
        // b[B[pos]]++; // 6: 4, 5: 1
        
        if (evaluate(a, A[pos]) || evaluate(b, B[pos])) {
            a.insert(A[pos]);
            b.insert(B[pos]);
            
            leave = backtrack(A, B, a, b, pos+1, cost);
        }
        else {
            leave = INT_MAX;
        }
        
        // a[A[pos]]--;
        // b[A[pos]]--;
        
        // option 2: swap numbers at position
        int rotate;
        
        // a[B[pos]]++;
        // b[A[pos]]++;
        
        if (evaluate(a, B[pos]) || evaluate(b, A[pos])) {
            a.insert(B[pos]);
            b.insert(A[pos]);
            rotate = backtrack(A, B, a, b, pos+1, cost+1);
        }
        else {
            rotate = INT_MAX;
        }
        
        // if (rotate != INT_MAX) {
        //     cout << rotate << ": ";
        //     for (int num : B)
        //         cout << num << " ";
        //     cout << endl;
        // }
        
        // a[B[pos]]--;
        // b[A[pos]]--;
        
        return min(leave, rotate);
    }
    
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        unordered_set<int> a, b;
        
        int res = backtrack(A, B, a, b, 0, 0);
        
        return res == INT_MAX ? -1 : res;
    }
};

/*
Good questions to ask or rephrase the problem:
- each element in A or B array is in the range [1, 6]
- we need to make all A[i] equal OR B[i] equal

Brute-force:
- 1) find the most frequent element to make it in greedy approach - might not work
- 2) try all swappes combinations - not efficient (backtracking)
- preprocess using sets/maps of elements in both rows to know how to construct

*/


// Discuss solution
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        
        // step 1: try to make all domino row A[0] in A or B
        int a = 0, b = 0;
        int i = 0;
        
        while (i < n && (A[i] == A[0] || B[i] == A[0])) {
            if (A[i] != A[0])
                a++; // swap with B[i] because it exists
            if (B[i] != A[0])
                b++; // swap with A[i] because it exists
            
            i++;
            if (i == n) // reached the end
                return min(a, b);
        }
        
        // step 2: try to make all domino row B[0] in A or B
        a = 0, b = 0;
        i = 0;
        
        while (i < n && (A[i] == B[0] || B[i] == B[0])) {
            if (A[i] != B[0])
                a++;
            if (B[i] != B[0])
                b++;
            
            i++;
            if (i == n)
                return min(a, b);
        }
        
        return -1;
    }
};