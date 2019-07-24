// https://leetcode.com/problems/distribute-candies-to-people/

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> distr(num_people); // initially all set to 0
        int count = 0;
        while (candies > 0) {
            int idx = count % num_people;
            if (count >= candies) count = candies-1; // left candies
            distr[idx] += ++count;
            candies -= count;
        }
        return distr;
    }
};