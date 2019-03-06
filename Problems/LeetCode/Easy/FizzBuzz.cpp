// https://leetcode.com/problems/fizz-buzz/submissions/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        
        for (int i = 1; i <= n; i++) {
            string word;
            
            if (i % 15 == 0)
                word = "FizzBuzz";
            else if (i % 3 == 0)
                word = "Fizz";
            else if (i % 5 == 0)
                word = "Buzz";
            else
                word = to_string(i);
            
            res.push_back(word);
        }
        
        return res;
    }
};