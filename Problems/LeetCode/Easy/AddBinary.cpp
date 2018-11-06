// https://leetcode.com/problems/add-binary/

// Note: too long code, reduce it
class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        int res_size = max(n, m);
        string res (res_size, 'x');
        
        int i = n-1, j = m-1, k = res_size-1;
        int carry = 0; // number to carry to the prev
        while (i >= 0 && j >= 0) {
            int sum = a[i]-'0' + b[j]-'0' + carry;
            if (sum > 1) {
                carry = 1;
                if (sum > 2)
                    res[k] = '1';
                else
                    res[k] = '0';
            }
            else {
                res[k] = sum+'0';
                carry = 0;
            }
            i--;
            j--;
            k--;
        }
        
        while (i >= 0) {
            int sum = a[i]-'0' + carry;
            if (sum > 1) {
                carry = 1;
                if (sum > 2)
                    res[k] = '1';
                else
                    res[k] = '0';
            }
            else {
                res[k] = sum+'0';
                carry = 0;
            }
            i--;
            k--;
        }
        
        while (j >= 0) {
            int sum = b[j]-'0' + carry;
            if (sum > 1) {
                carry = 1;
                if (sum > 2)
                    res[k] = '1';
                else
                    res[k] = '0';
            }
            else {
                res[k] = sum+'0';
                carry = 0;
            }
            j--;
            k--;
        }
        
        if (carry == 1) {
            string new_res (res_size+1, 'x');
            new_res[0] = '1';
            i = 0;
            while (i < res_size) {
                new_res[i+1] = res[i];
                i++;
            }
            return new_res;
        }
        
        return res;
    }
};