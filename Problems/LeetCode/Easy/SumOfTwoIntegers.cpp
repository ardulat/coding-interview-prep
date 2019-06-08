// https://leetcode.com/problems/sum-of-two-integers/submissions/

/*
    The solution below failed many times because of the implementation
    of arithmetic shifts in C++. It is said that the behaviour
    of arithmetic right shift on signed negative number is undefined.
    The case with right shifting negative numbers cause problem
    because it adds leading 1s instead of 0s according to Leetcode
    compiler implementation which is unexpected.
*/
class Solution {
public:
    /*
    - 0, 0, 0
    - 0, 0, 1
    - 0, 1, 0
    - 0, 1, 1
    - 1, 0, 0
    - 1, 0, 1
    - 1, 1, 0
    - 1, 1, 1
    */
    pair<int,int> add(int a, int b, int carry) {
        pair<int,int> sum_carry;
        sum_carry.first = 0;
        sum_carry.second = 0;
        if (a == 0) {
            if (b == 1 && carry == 1)
                sum_carry.second = 1;
            else if ((b == 1 && carry == 0) ||
                (b == 0 && carry == 1))
                sum_carry.first = 1;
        } else {
            if (b == 1 && carry == 1) // 111
                sum_carry = make_pair(1,1);
            else if ((b == 1 && carry == 0) ||
                (b == 0 && carry == 1)) // 101 || 110 -> carry = 1, sum = 0
                sum_carry.second = 1;
            else
                sum_carry.first = 1;
        }
        return sum_carry;
    }
    
    int getSum(int a, int b) {
        int mask = 1; // ...0001 -> to get the last bit
        int carry = 0;
        int total = 0;
        int bit_pos = 0; // or 1?
        bool isSigned = false;
        // cout << bitset<32>(a) << endl;
        // cout << bitset<32>(b) << endl << endl;
        if (a < 0 || b < 0)
            isSigned = true;
        while (a > 0 || b > 0 ||
              (a < 0 && b < 0 && bit_pos < 32)) {
            int last_a = a & mask;
            int last_b = b & mask;
            pair<int,int> sum_carry = add(last_a, last_b, carry);
            int sum = sum_carry.first;
            carry = sum_carry.second;
            total = total | (sum << bit_pos); // OR
            bit_pos++;
            a = a >> 1;
            b = b >> 1;
        }
        int temp = bit_pos;
        while (a > 0 || (a < 0 && bit_pos < 32)) {
            int last_a = a & mask;
            pair<int,int> sum_carry = add(last_a, 0, carry);
            int sum = sum_carry.first;
            carry = sum_carry.second;
            total = total | (sum << bit_pos); // OR
            bit_pos++;
            // 0000 | 0001 = 0001
            // 0001 << 1 = 0010
            a = a >> 1;
        }
        while (b > 0 || (b < 0 && bit_pos < 32)) {
            int last_b = b & mask;
            pair<int,int> sum_carry = add(0, last_b, carry);
            int sum = sum_carry.first;
            carry = sum_carry.second;
            total = total | (sum << bit_pos); // OR
            bit_pos++;
            b = b >> 1;
        }
        if (!isSigned && carry == 1)
            total = total | (carry << bit_pos);
        return total;
    }
};
