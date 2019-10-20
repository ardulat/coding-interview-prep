// https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    /*
    - divide: everytime split array into two subarrays from mid element
    - conquer: find the largest area in left and right subarrays
    - combine: compute the max area across all array
    
    base case:
    - empty => area 0
    - 1 element => the area is equal to itself
    - 2 elements => area is equal twice of max of heights
    */
    
    int combine(vector<int>& heights, int start, int mid, int end) {
        int i = mid, j = mid+1;
        int area = 0, h = min(heights[i], heights[j]);
        
        while (i >= start && j <= end) {
            // cout << i << " " << j << endl;
            h = min(h, min(heights[i], heights[j]));
            area = max(area, h * (j-i+1));
            
            if (i == start)
                j++;
            else if (j == end)
                i--;
            else {
                if (heights[i-1] > heights[j+1])
                    i--;
                else
                    j++;
            }
        }
        
        return area;
    }
    
    int divideConquer(vector<int>& heights, int start, int end) {
        if (start > end)
            return 0;
        if (start == end)
            return heights[start];
        
        int mid = (start+end)/2;
        // cout << start << " " << mid << " " << end << endl;
        int leftArea = divideConquer(heights, start, mid);
        int rightArea = divideConquer(heights, mid+1, end);
        
        int midArea = combine(heights, start, mid, end);
        
        return max(max(leftArea, rightArea), midArea);
    }
    
    int largestRectangleArea(vector<int>& heights) {
        return divideConquer(heights, 0, heights.size()-1);
    }
};