// https://www.interviewbit.com/problems/rotated-array/

// REVIEW THE PROBLEM
int Solution::findMin(const vector<int> &A) {
    int N = A.size();
    int low = 0, high = N-1;
    
    
    while (low <= high) {
        if (A[low] <= A[high]) // Case 1
            return A[low];
        int mid = (low+high)/2;
        int next = (mid+1) % N;
        int prev = (mid+N-1) % N;
        
        if (A[mid] <= A[next] && A[mid] <= A[prev]) // Case 2
            return A[mid];
        if (A[mid] <= A[high]) // Case 3
            high = mid-1;
        if (A[mid] >= A[low]) // Case 4
            low = mid+1;
    }
    
    return -1; // for invalid input
}