// https://leetcode.com/problems/3sum/

// Approach:
// Run a loop from i=0 to n-2
//   Create an empty hash set
//   Run inner loop from j=i+1 to n-1
//       If -(arr[i] + arr[j]) is present in hash set
//          print arr[i], arr[j] and -(arr[i]+arr[j])
//       Else
//          Insert arr[j] in hash set.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        // base case:
        if (nums.empty())
            return result;
        
        set<vector<int>> s;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size()-1; i++) {
            unordered_set<int> hashset;
            for (int j = i+1; j < nums.size(); j++) {
                int x = -(nums[i]+nums[j]);
                if (hashset.find(x) != hashset.end()) {
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[j]);
                    triplet.push_back(x);
                    s.insert(triplet);
                }
                else
                    hashset.insert(nums[j]);
            }
        }
        
        for (auto t : s)
            result.push_back(t);
        
        return result;
    }
};

// Approach:
// 1. Sort all element of array
// 2. Run loop from i=0 to n-2.
//      Initialize two index variables l=i+1 and r=n-1
// 4. while (l < r) 
//      Check sum of arr[i], arr[l], arr[r] is
//      zero or not if sum is zero then print the
//      triplet and do l++ and r--.
// 5. If sum is less than zero then l++
// 6. If sum is greater than zero then r--
// 7. If not exist in array then print not found.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        set<vector<int>> s;
        
        for (int i = 0; i < n-1; i++) {
            int l = i+1;
            int r = n-1;
            
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                
                if (sum == 0) {
                    vector<int> triplet;
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[l]);
                    triplet.push_back(nums[r]);
                    // result.push_back(triplet);
                    s.insert(triplet);
                    l++; r--;
                }
                else if (sum < 0)
                    l++;
                else
                    r--;
            }
        }
        
        for (auto triplet : s)
            result.push_back(triplet);
        
        return result;
    }
};