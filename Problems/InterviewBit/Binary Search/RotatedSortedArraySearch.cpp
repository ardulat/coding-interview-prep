// https://www.interviewbit.com/problems/rotated-sorted-array-search/

int countRotations(const vector<int> &A) {
    int N = A.size();
    int low = 0, high = N-1;
    
    while (low <= high) {
        if (A[low] <= A[high]) // Case 1
            return low;
        int mid = (low+high)/2;
        int next = (mid+1) % N;
        int prev = (mid+N-1) % N;
        
        if (A[mid] <= A[next] && A[mid] <= A[prev]) // Case 2
            return mid;
        if (A[mid] <= A[high]) // Case 3
            high = mid-1;
        if (A[mid] >= A[low]) // Case 4
            low = mid+1;
    }
    
    return -1;
}

int Solution::search(const vector<int> &A, int B) {
    int rotationsCount = countRotations(A);
    
    int start = 0;
    int end = A.size()-1;
    
    while(start <= end) {
        int mid = ((start+end)/2+rotationsCount) % A.size();
        // cout << "start = " << start << " end = " << end << " mid = " << mid << endl;
        if (A[mid] == B)
            return mid;
        else if (A[mid] > B)
            end = (start+end)/2-1;
        else
            start = (start+end)/2+1;
    }
    
    return -1;
}
