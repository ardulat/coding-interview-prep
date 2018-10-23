// https://www.interviewbit.com/problems/diffk-ii/

// Note: look for ways to insert a pair to unordered_map

int Solution::diffPossible(const vector<int> &A, int B) {
    unordered_map<int, int> ht;
    
    for (int i = 0; i < A.size(); i++)
        ht.insert(make_pair(A[i],i));
        
    for (int i = 0; i < A.size(); i++) {
        if (ht.find(B+A[i]) != ht.end())
            if (ht[B+A[i]] != i)
                return 1;
    }
    return 0;
}
