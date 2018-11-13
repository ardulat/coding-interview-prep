// https://leetcode.com/problems/add-binary/

class Solution {
public:
    int convert2int(char num) {
        return num-'0';
    }
    
    char convert2char(int num) {
        return num+'0';
    }
    
    string addBinary(string a, string b) {
        string result = "";
        int carry = 0;
        int sum = 0;
        
        int i = a.size()-1, j = b.size()-1;
        cout << a[i] << ' '<< a[j] << endl;
        
        while (i >= 0 || j >= 0 || carry != 0) {
            sum = 0;
            if (i >= 0)
                sum += convert2int(a[i]);
            if (j >= 0)
                sum += convert2int(b[j]);
            sum += carry;
            
            result = convert2char(sum % 2) + result;
            
            carry = sum / 2;
            
            i--;
            j--;
        }
        
        return result;
    }
};