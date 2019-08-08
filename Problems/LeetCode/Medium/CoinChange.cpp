// https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChangeUtil(vector<int>& coins, int amount, unordered_map<int,int>& amount2coin) {
        if (amount < 0)
            return -1;
        else if (amount == 0) {
            return 0;
        }
        else if (amount2coin[amount])
            return amount2coin[amount];
        int minCount = INT_MAX;
        for (int coin : coins) {
            int res = coinChangeUtil(coins, amount-coin, amount2coin);
            if (res >= 0 && res < minCount)
                minCount = res+1;
        }
        amount2coin[amount] = (minCount == INT_MAX) ? -1 : minCount;
        return amount2coin[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int,int> amount2coin;
        
        return coinChangeUtil(coins, amount, amount2coin);
    }
};