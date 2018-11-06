// https://leetcode.com/problems/sqrtx/

// Brute-force:
class Solution {
public:
    int mySqrt(int x) {
        int i = 1;
        int res = 0;
        
        while ((long long) i*i <= x) {
            res = i;
            i++;
        }
        
        return res;
    }
};

// Binary search:
class Solution {
public:
    int mySqrt(int x) {
        // base case:
        if (x == 1)
            return 1;
        
        int start = 0, end = x;
        
        while (start < end) {
            int mid = (start+end)/2;
            long long product1 = (long long) mid*mid;
            long long product2 = (long long) (mid+1)*(mid+1);
            if (product1 <= x && product2 > x)
                return mid;
            else if (product1 > x)
                end = mid;
            else
                start = mid+1;
        }
        
        return 0;
    }
};