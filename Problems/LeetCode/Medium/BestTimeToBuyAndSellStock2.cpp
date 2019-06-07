// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/solution/

// Brute-Force: TLE
class Solution {
public:
    /*
    [7,1,3,5,6,4]
    2+1
    */
    int maxProfit(vector<int>& prices, int index) {
        if (index+1 >= prices.size()) // TO-DO: verify
            return 0; // sell
        if (prices[index] >= prices[index+1])
            return maxProfit(prices, index+1); // go to the next
        int max_profit = 0;
        int i = index+1; // sell index
        while (i < prices.size()) {
            int profit = 0;
            if (prices[index] < prices[i]) { // sell
                profit = prices[i] - prices[index] + maxProfit(prices,i+1);
            }
            if (profit > max_profit)
                max_profit = profit;
            i++;
        }
        return max_profit;
    }
    
    int maxProfit(vector<int>& prices) {
        return maxProfit(prices, 0);
        // return 0;
    }
};

// Problem with the approach: Buy and Sell transactions happen at the same date
class Solution {
public:
    /*
    [7,1,3,5,6,4]
    [7, 1, 5, 3, 6, 4]
    */
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int i = 0;
        int valley = prices[i];
        int peak = prices[i];
        int max_profit = 0;
        int len = prices.size();
        while (i < len-1) {
            while (i < len-1 && prices[i] >= prices[i+1]) // bearish
                i++;
            valley = prices[i]; // bottom point
            while (i < len-1 && prices[i] < prices[i+1]) // bullish
                i++;
            peak = prices[i];
            max_profit += peak-valley;
        }
        return max_profit;
    }
};