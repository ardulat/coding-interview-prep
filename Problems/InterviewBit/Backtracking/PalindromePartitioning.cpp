// https://www.interviewbit.com/problems/palindrome-partitioning/

// TO-DO: Review the problem
// Algorithm taken from: https://www.geeksforgeeks.org/given-a-string-print-all-possible-palindromic-partition/

bool isPalindrome(string str, int low, int high) { 
    while (low < high) { 
        if (str[low] != str[high]) 
            return false; 
        low++; 
        high--; 
    } 
    return true; 
} 

void subsets(string A, vector<vector<string>> &results, vector<string> &row, int index) {
    
    if (index == A.size())
        results.push_back(row);
        
    for (int i = index; i < A.size(); i++) {
        if (isPalindrome(A, index, i)) {
            row.push_back(A.substr(index, i-index+1));
            subsets(A, results, row, i+1);
            row.pop_back();
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>> results;
    vector<string> row;
    int index = 0;
    subsets(A, results, row, index);
    return results;
}
