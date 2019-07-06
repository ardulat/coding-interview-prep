// https://leetcode.com/problems/reveal-cards-in-increasing-order/

class Solution {
public:
    /*
    [2,13,3,11,5,17,7]
    sorted = [2,3,5,7,11,13,17]
    */
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> index;
        for (int i = 0; i < deck.size(); i++)
            index.push_back(i);
        sort(deck.begin(), deck.end());
        vector<int> res(deck.size(), 0);
        for (int num : deck) {
            res[index.front()] = num;
            index.pop_front(); // remove the card
            if (!index.empty()) {
                index.push_back(index.front());
                index.pop_front();
            }
        }
        return res;
    }
};