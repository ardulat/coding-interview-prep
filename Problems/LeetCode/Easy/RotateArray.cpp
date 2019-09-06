// https://leetcode.com/problems/rotate-array/

class Solution {
public:
    /*
    [1,2,3,4,5,6,7]
    [1,2,3,4,5,6,7,8] -> 3 steps: [6,7,8,1,2,3,4,5]
    */
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> shift(k,0);
        
        for (int i = n-k; i < n; i++)
            shift[i-(n-k)] = nums[i]; // copy the last k elements
        
        for (int i = n-1; i >= k; i--)
            nums[i] = nums[i-k]; // copy the first n-k elements to the end
        
        for (int i = 0; i < k; i++)
            nums[i] = shift[i]; // copy the shifted elements from extra array
    }
};

// Algorithm 2: reverse

class Solution {
public:
    /*
    [1,2,3,4,5,6,7]
    */
    void reverse(vector<int>& nums, int i, int j) {
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        // reverse all
        int i = 0, j = n-1;
        reverse(nums, i, j);
        
        // reverse first k elements
        i = 0, j = k-1;
        reverse(nums, i, j);
        
        // reverse last n-k elements
        i = k, j = n-1;
        reverse(nums, i, j);
    }
};


// TO-DO: finish cyclomatic solution
class Solution {
public:
    /*
    [1,2,3,4,5,6,7]
    
    [1,2,3,4,5,6,7,8] -> 3 steps: [6,7,8,1,2,3,4,5]
    
    temp = 2
    
    [1,2,3]
    [1,2,3] -> 2 steps: 
    
    temp = 1
    
    [1,2,7,1,5,6,4] -> 3 steps: [5,6,7,1,2,3,4]
    
    temp = 3
    idx = 3+1 = 4
    */
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        if (k == 0)
            return;
        
        int temp;
        
        for (int i = 0; i < k; i++) {
            temp = nums[i];
            int idx = k+i;
            while (idx < n+k) {
                // cout << idx << endl;
                swap(temp, nums[idx % n]);
                
                idx += k;
                // cout << idx << endl << endl;
            }
        }
    }
};