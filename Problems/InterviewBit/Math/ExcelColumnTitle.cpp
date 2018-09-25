// https://www.interviewbit.com/problems/excel-column-title/

string Solution::convertToTitle(int A) {
    string result = "";
    
    while (A > 0) {
        int x = (A-1) % 26;
        result += char(65+x);
        A = (A-1) / 26;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}
