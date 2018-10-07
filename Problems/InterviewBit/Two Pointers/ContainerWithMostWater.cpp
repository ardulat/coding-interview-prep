// https://www.interviewbit.com/problems/container-with-most-water/

// Brute-force
int Solution::maxArea(vector<int> &A) {
    int maxContainer = 0;
    
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A.size(); j++)
            if (min(A[i],A[j])*(j-i) > maxContainer)
                maxContainer = min(A[i],A[j])*(j-i);
            
    return maxContainer;
}

// Optimal solution
int Solution::maxArea(vector<int> &A) {
    int maxContainer = 0;
    int i = 0, j = A.size()-1;
    
    while (i < j) {
        if (maxContainer < min(A[i],A[j])*(j-i))
            maxContainer = min(A[i],A[j])*(j-i);            
        if (min(A[i],A[j]) == A[i])
            i++;
        else if (min(A[i],A[j]) == A[j])
            j--;
    }
            
    return maxContainer;
}
