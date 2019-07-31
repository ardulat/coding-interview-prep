// https://leetcode.com/problems/maximum-swap/

class Solution {
public:
    /*
    2376 -> 7326
    23776 -> 73726
    123599997 -> 923599917
    923599997 -> 993599927
    
    - find the rightmost greatest number
    - swap it with leftmost lower number
    */
    int maximumSwap(int num) {
        string str = to_string(num);
        int i = 0;
        while (i < str.length()-1) {
            if (str[i]-'0' < str[i+1]-'0')
                break;
            i++;
        }
        if (i == str.length()-1) return num; // no changes
        int greatest = 0, right;
        i++;
        while (i < str.length()) {
            if (greatest <= str[i]-'0') {
                greatest = str[i]-'0';
                right = i;
            }
            i++;
        }
        for (int i = 0; i < str.length(); i++)
            if (str[i]-'0' < greatest) {
                swap(str[i], str[right]);
                break;
            }
        return stoi(str);
    }
};