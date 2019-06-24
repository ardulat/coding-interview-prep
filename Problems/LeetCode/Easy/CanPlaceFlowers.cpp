// https://leetcode.com/problems/can-place-flowers/

class Solution {
public:
    /*
    list of adjacent at 0: A[i+1]
    list of adjacent at i: A[i-1] and A[i+1]
    list of adjacent at m: A[i-1]
    */
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0, m = flowerbed.size();
        
        while (n > 0 && i < m) {
            if (flowerbed[i] == 0 &&
                ((m == 1) ||
                 (i == 0 && flowerbed[i+1] == 0) ||
                 (i == m-1 && flowerbed[i-1] == 0) ||
                 (i > 0 && i < m-1 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0))) {
                flowerbed[i] = 1;
                n--;
            }
            i++;
        }
        
        return n == 0;
    }
};