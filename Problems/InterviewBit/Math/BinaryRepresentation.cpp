// https://www.interviewbit.com/problems/binary-representation/

string Solution::findDigitsInBinary(int A) {
    string binary = "";
    
    while(A > 0) {
        int rem = A % 2;
        binary += to_string(rem);
        A = A/2;
    }
    
    if (binary.empty())
        binary = "0";
    
    reverse(binary.begin(), binary.end());
    
    return binary;
}
