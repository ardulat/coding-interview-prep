// https://www.interviewbit.com/problems/square-root-of-integer/

int Solution::sqrt(int A) {
    
    long start = 1;
    long end = (long)A-1;
    
    while (start <= end) {
        long mid = start+(end-start)/2;
        
        if (mid*mid == A)
            return mid;
        else if (mid*mid > A)
            end = mid-1;
        else {
            if ((mid+1)*(mid+1) > A)
                return mid;
            else
                start = mid+1;
        }
    }
    
    if (A == 1)
        return 1;
    if (A == 0)
        return 0;
    
    return -1;
}
