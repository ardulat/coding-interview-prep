// https://leetcode.com/problems/k-th-symbol-in-grammar/

class Solution {
public:
    /*
    Brute-force: TLE
    - generate all N rows
    
    Optimization:
    - we do not care about not K symbols
    - like in the binary tree, refer to its parent's symbol
    
    01101001
    0110100110010110
    */
    
    int kthGrammar(int N, int K) {
        if (N == 1)
            return 0;
        
        if (K % 2 == 0) { // K is even -> parent is at K/2 position, K is right child
            int parent = kthGrammar(N-1, K/2);
            if (parent == 0)
                return 1;
            else
                return 0;
        }
        else { // K is odd -> parent is at (K+1)/2 position, K is left child
            int parent = kthGrammar(N-1, (K+1)/2);
            if (parent == 0)
                return 0;
            else
                return 1;
        }
    }
};