// https://www.interviewbit.com/problems/roman-to-integer/

int Solution::romanToInt(string A) {
    int i = 0, count = 0;
    
    while (i < A.length()) {
        if (A[i] == 'I') {
            if (A[i+1] == 'V') {
                count += 4; i += 2;
            }
            else if (A[i+1] == 'X') {
                count += 9; i += 2;
            }
            else if (A[i+1] == 'C') {
                count += 99; i += 2;
            }
            else if (A[i+1] == 'D') {
                count += 499; i += 2;
            }
            else if (A[i+1] == 'M') {
                count += 999; i += 2;
            }
            else {
                count++; i++;
            }
        }
        else if (A[i] == 'V') {
            count += 5; i++;
        }
        else if (A[i] == 'X') {
            if (A[i+1] == 'L') {
                count += 40; i += 2;
            }
            else if (A[i+1] == 'C') {
                count += 90; i += 2;
            }
            else if (A[i+1] == 'D') {
                count += 490; i += 2;
            }
            else if (A[i+1] == 'M') {
                count += 990; i += 2;
            }
            else {
                count += 10; i++;
            }
        }
        else if (A[i] == 'L') {
            count += 50; i++;
        }
        else if (A[i] == 'C') {
            if (A[i+1] == 'D') {
                count += 400; i += 2;
            }
            else if (A[i+1] == 'M') {
                count += 900; i += 2;
            }
            else {
                count += 100; i++;
            }
        }
        else if (A[i] == 'D') {
            count += 500; i++;
        }
        else if (A[i] == 'M') {
            count += 1000; i++;
        }
        else
            i++;
    }
    return count;
}
