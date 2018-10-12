// https://www.interviewbit.com/problems/letter-phone/

void combinations(string &A, int index, string &str, vector<string> &dict, vector<string> &results) {
    int i = (int)(A[index]) - '0';
    string temp = dict[i];
    if (index == A.size()-1) {
        for(char ch : temp) {
            str[index] = ch;
            results.push_back(str);
        }
        return;
    }
    for(char ch : temp) {
        str[index] = ch;
        combinations(A, index+1, str, dict, results);
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> dict = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string str(A.size(), 'x'); // string of length A.size() with all "x"
    vector<string> results;
    int index = 0;
    combinations(A, index, str, dict, results);
    return results;
}
