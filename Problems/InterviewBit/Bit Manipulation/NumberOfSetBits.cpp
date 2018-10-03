// https://www.interviewbit.com/problems/number-of-1-bits/

int Solution::numSetBits(unsigned int A) {
    int count = 0;
    int lowestBit;
    
    while(A != 0) {
        lowestBit = A & ~(A-1);
        if (lowestBit == 1)
            count++;
        A = A >> 1;
    }
    return count;
}
