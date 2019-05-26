// https://leetcode.com/contest/weekly-contest-138/problems/grumpy-bookstore-owner/

class Solution {
public:
    /*
    - sliding window approach
    - calculate everything without changes (according to rules)
    - everytime using sliding window add/subtract the changed grumpy minutes
    - count the maximum of them
    */
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int satisfied = 0;
        for (int i = 0; i < customers.size(); i++)
            if (grumpy[i] != 1)
                satisfied += customers[i];
        // initial window
        int window = satisfied, i = 0;
        while (i < X && i < customers.size()) {
            if (grumpy[i] == 1)
                window += customers[i];
            i++;
        }
        int max_window = window;
        while (i < customers.size()) {
            if (grumpy[i-X] == 1)
                window -= customers[i-X];
            if (grumpy[i] == 1)
                window += customers[i];
            max_window = max(max_window, window);
            i++;
        }
        return max_window;
    }
};