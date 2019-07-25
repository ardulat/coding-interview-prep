// https://leetcode.com/problems/largest-time-for-given-digits/

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        unordered_map<int,int> hashmap;
        for (int num : A) hashmap[num]++;
        string res = "";
        for (int i = 2; i >= 0; i--)
            if (hashmap[i]) {
                hashmap[i]--;
                int max_hour = i == 2 ? 3 : 9;
                for (int j = max_hour; j >= 0; j--)
                    if (hashmap[j]) {
                        hashmap[j]--;
                        int hours = i*10+j;
                        // look for minutes
                        for (int k = 5; k >= 0; k--)
                            if (hashmap[k]) {
                                hashmap[k]--;
                                for (int l = 9; l >= 0; l--)
                                    if (hashmap[l]) {
                                        int minutes = k*10+l;
                                        // edge case with leading 0:
                                        if (hours < 10) res += "0";
                                        res += to_string(hours)+":";
                                        if (minutes < 10) res += "0";
                                        res += to_string(minutes);
                                        return res;
                                    }
                                hashmap[k]++;
                            }
                        hashmap[j]++;
                    }
                hashmap[i]++;
            }
        return "";
    }
};