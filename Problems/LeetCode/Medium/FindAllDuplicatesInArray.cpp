// https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution {
public:
    /*
    Algorithm 0 (brute-force):
    - iterate through each element
    - find through another linear scan if the value is present in array
    Drawback: O(N^2) time
    
    Algorithm 1:
    - sort everything
    - check whether next element is equal to the current one
    - if yes, add it to the result array
    Drawback: O(NlogN) time
    
    Algorithm 2:
    - linearly scan the array
    - put everything to hashset
    - if the number is present in the hashset, add it to the result array
    Drawback: O(N) space
    

    [4,3,2,7,8,2,3,1]
    
    Optimal algorithm satisfying the requirements:
    - for a number X at the position i, set the number Y at position X-1 to negative
    - if the number is positive, then it means previously it was negative
    - therefore, it occured previously
    - therefore, it is a duplicate
    - push it to the resultant array
    */
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]); // has to be in range [1,n]
            nums[index-1] = -nums[index-1];
            if (nums[index-1] > 0) // if it is positive
                result.push_back(index);
        }
        return result;
    }
};