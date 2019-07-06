// https://leetcode.com/problems/n-repeated-element-in-size-2n-array/

class Solution {
public:
    /*
    Algorithm 1: time = O(NlogN), space = O(1)
    - sort the array
    - look for the repeated element
    
    Algorithm 2: time = O(N), space = O(N)
    - use unordered_set<int> to maintain the elements
    - if element is present in the set, return it
    
    Algorithm 3: time = O(N), space = O(1)
    - use the constraint of non-negative elements by negating the element at the index of the number
    - problem: the range may be out of the range of array (index out of bounds)
    */
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> hs;
        for (int num : A) {
            if (hs.find(num) != hs.end())
                return num;
            hs.insert(num);
        }
        return 0;
    }
};