// https://www.interviewbit.com/problems/count-element-occurence/

int binarySearch(vector<int> A, int x, bool searchFirst) {
    int start = 0, end = A.size()-1, result = -1;
    
    while(start <= end) {
        int mid = (start+end)/2;
        if (x == A[mid]) {
            result = mid;
            if (searchFirst) // go left
                end = mid-1;
            else // go right
                start = mid+1;
        }
        else if (x < A[mid]) // search left
            end = mid-1;
        else // search right
            start = mid+1;
    }
    return result;
} 

// O(logN)
int Solution::findCount(const vector<int> &A, int B) {
    int first = binarySearch(A, B, true);
    int last = binarySearch(A, B, false);
    if (first == -1 || last == -1) // no such number
        return 0;
    return last-first+1;
}
