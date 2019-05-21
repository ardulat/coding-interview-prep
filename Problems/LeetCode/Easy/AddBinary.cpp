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

// Solution 2:
class Solution {
public:
    /*
    - construct simple binary added with carry and sum
    - start two pointers from the end of each string
    - at each time add the numbers
    - pass carry to the next sum
    - calculate left characters
    */
    pair<char,char> addThree(char a, char b, char prevCarry) {
        char carry, sum;
        int intSum = a-'0'+b-'0'+prevCarry-'0';
        if (intSum == 3) {
            carry = '1';
            sum = '1';
        } else if (intSum == 2) {
            carry = '1';
            sum = '0';
        } else if (intSum == 1) {
            carry = '0';
            sum = '1';
        } else {
            carry = '0';
            sum = '0';
        }
        return {carry, sum};
    }
    
    string addBinary(string a, string b) {
        int indA = a.size()-1, indB = b.size()-1;
        char carry = '0', sum;
        string ans = ""; // reverse at the end
        while (indA > -1 && indB > -1) {
            pair<char,char> carrySum = addThree(a[indA], b[indB], carry);
            carry = carrySum.first;
            sum = carrySum.second;
            ans += sum;
            indA--;
            indB--;
        }
        while (indA > -1) {
            pair<char,char> carrySum = addThree(a[indA], '0', carry);
            carry = carrySum.first;
            sum = carrySum.second;
            ans += sum;
            indA--;
        }
        while (indB > -1) {
            pair<char,char> carrySum = addThree('0', b[indB], carry);
            carry = carrySum.first;
            sum = carrySum.second;
            ans += sum;
            indB--;
        }
        if (carry == '1') {
            ans += carry;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
