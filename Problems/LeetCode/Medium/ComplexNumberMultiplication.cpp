// https://leetcode.com/problems/complex-number-multiplication/

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        // step 1: parsing
        string real_a = "", real_b = "", complex_a = "", complex_b = "";
        bool neg_real_a = false, neg_real_b = false, neg_complex_a = false, neg_complex_b = false;
        int i = 0, j = 0;
        if (a[i] == '-') {
            neg_real_a = true;
            i++;
        }
        if (b[j] == '-') {
            neg_real_b = true;
            j++;
        }
        while (a[i] != '+') {
            real_a += a[i];
            i++;
        }
        i++;
        while (b[j] != '+') {
            real_b += b[j];
            j++;
        }
        j++;
        int real_a_num = stoi(real_a), real_b_num = stoi(real_b);
        if (a[i] == '-') {
            neg_complex_a = true;
            i++;
        }
        if (b[j] == '-') {
            neg_complex_b = true;
            j++;
        }
        while (a[i] != 'i') {
            complex_a += a[i];
            i++;
        }
        while (b[j] != 'i') {
            complex_b += b[j];
            j++;
        }
        // step 2: calculation
        int complex_a_num = stoi(complex_a), complex_b_num = stoi(complex_b);
        if (neg_real_a) real_a_num = -real_a_num;
        if (neg_real_b) real_b_num = -real_b_num;
        if (neg_complex_a) complex_a_num = -complex_a_num;
        if (neg_complex_b) complex_b_num = -complex_b_num;
        int real, complex;
        real = real_a_num*real_b_num - complex_a_num*complex_b_num;
        complex = real_a_num*complex_b_num + real_b_num*complex_a_num;
        // step 3: constructing
        string res = "";
        if (real < 0) {
            res += '-';
            real = -real;
        }
        res += to_string(real) + '+';
        if (complex < 0) {
            res += '-';
            complex = -complex;
        }
        res += to_string(complex) + 'i';
        
        return res;
    }
};