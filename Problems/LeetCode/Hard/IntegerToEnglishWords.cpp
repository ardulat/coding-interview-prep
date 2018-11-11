// https://leetcode.com/problems/integer-to-english-words/

class Solution {
private:
    vector<string> underTwenty = {"", "One", "Two", "Three", "Four", "Five", 
                                  "Six", "Seven", "Eight", "Nine", "Ten", 
                                  "Eleven", "Twelve", "Thirteen", "Fourteen",
                                  "Fifteen", "Sixteen", "Seventeen", "Eighteen",
                                  "Nineteen", "Twenty"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty",
                           "Sixty", "Seventy", "Eighty", "Ninety"};

    string int2string(int n) {
        if (n >= 1000000000) // billion
            return int2string(n/1000000000)+" Billion"+int2string(n%1000000000);
        else if (n >= 1000000) // million
            return int2string(n/1000000)+" Million"+int2string(n%1000000);
        else if (n >= 1000) // thousand
            return int2string(n/1000)+" Thousand"+int2string(n%1000);
        else if (n >= 100) // hundred
            return int2string(n/100)+" Hundred"+int2string(n%100);
        else if (n >= 20) // more than twenty
            return " "+tens[n/10]+int2string(n%10);
        else if (n >= 1) // digits
            return " "+underTwenty[n];
        return ""; // case n = 0
    }
    
public:
    string numberToWords(int num) {
        // base case:
        if (num == 0)
            return "Zero";
        string result = int2string(num);
        return result.substr(1, result.size()-1);
    }
};