// https://www.interviewbit.com/problems/matrix-search/

int binarySearch(vector<int> &A, int B) {
    int start = 0;
    int end = A.size()-1;
    
    while (start <= end) {
        int mid = (start+end)/2;
        
        if (A[mid] == B)
            return mid;
        else if (A[mid] > B) // search left
            end = mid-1;
        else                 // search right
            start = mid+1;
    }
    
    return -1;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int m = A.size();
    
    for (int i = 0; i < m; i++) {
        if (binarySearch(A[i], B) != -1)
            return 1;
    }
    
    return 0;
}
