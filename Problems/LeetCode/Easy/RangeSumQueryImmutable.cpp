// https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
private:
    vector<int> arr;
public:
    /*
    [-2, 0, 3, -5, 2, -1]
     0   1  2  3   4   5   6
    [0, -2, -2, 1, -4, -2, -3]
    
    sum(0, 2) -> 1
    sum(2, 5) -> -1
    */
    NumArray(vector<int>& nums) {
        arr = vector(nums.size()+1, 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            arr[i+1] = sum;
        }
    }
    
    int sumRange(int i, int j) {
        // cout << arr[j+1] << " - " << arr[i] << endl;
        return arr[j+1]-arr[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */