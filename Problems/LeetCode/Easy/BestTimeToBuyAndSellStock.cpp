// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Brute-force:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i+1; j < prices.size(); j++) {
                int diff = prices[j] - prices[i];
                if (diff > profit)
                    profit = diff;
            }
        }
        
        return profit;
    }
};

// Approach:
// Find local min, and local max,
// calculate the difference, update profit if needed
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = INT_MAX;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice)
                minPrice = prices[i];
            if (prices[i]-minPrice > profit)
                profit = prices[i]-minPrice;
        }
        
        return profit;
    }
};