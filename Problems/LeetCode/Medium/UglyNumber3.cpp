// 

// TLE
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        if (n == 0)
            return 0;
        
        int ptra = 0, ptrb = 0, ptrc = 0;
        int k;
        
        for (int i = 0; i < n; i++) {
            int first = ptra*a+a; // 2
            int second = ptrb*b+b; // 3
            int third = ptrc*c+c; // 4
            
            k = min(first, min(second, third)); // 2
            
            if (k == first) ptra++;
            if (k == second) ptrb++;
            if (k == third) ptrc++;
        }
        
        return k;
    }
};

// Binary-Search
class Solution {
public:
    long lcm(long a, long b) {
        return a*b / gcd(a, b);
    }
    
    long count(long num, long a, long b, long c) {
        int res = 0;
        res += num/a;
        res += num/b;
        res += num/c;
        
        res -= num/lcm(a,b);
        res -= num/lcm(b,c);
        res -= num/lcm(a,c);
        
        res += num/lcm(a, lcm(b, c));
        
        return res;
    }
    
    #define MAX_ANS 2*10e9
    int nthUglyNumber(int n, int a, int b, int c) {
        int left = 1;
        int right = n * min(a, min(b, c));
        right = MAX_ANS;
        int res = 0;
        
        while (left < right) {
            int mid = left + (right-left) / 2;
            
            long cnt = count(mid, a, b, c);
            if (cnt < n) {
                left = mid+1;
            }
            else {
                res = mid;
                right = mid;
            }
        }
        
        return res;
    }
};