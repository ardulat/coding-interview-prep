// https://leetcode.com/problems/maximum-product-of-three-numbers/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // linear scan
        int min1 = 1000, min2 = 1000;
        int max1 = -1000, max2 = -1000, max3 = -1000;
        for (int x : nums) {
            if (x < min1) {
                min2 = min1;
                min1 = x;
            }
            else if (x < min2)
                min2 = x;
            if (x > max1) {
                max3 = max2;
                max2 = max1;
                max1 = x;
            }
            else if (x > max2) {
                max3 = max2;
                max2 = x;
            }
            else if (x > max3)
                max3 = x;
        }
        cout << min1 << " " << min2 << endl;
        cout << max3 <<" "<< max2 <<" "<< max1 << endl;
        
        return max(max1*min1*min2, max3*max2*max1);
    }
};