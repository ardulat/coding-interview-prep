// https://www.interviewbit.com/problems/spiral-order-matrix-i/

#include <cstdio>
#include <vector>

using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
    vector<int> result;
    
    int m = A.size();
    int n = A[0].size();
    
    int T = 0;
    int B = m-1;
    int L = 0;
    int R = n-1;
    int dir = 0;
    int i;
    
    while (T<=B && L<=R) {
        if (dir == 0) {
            for (i = L; i <= R; i++)
                result.push_back(A[T][i]);
            dir++; T++;
        } else if (dir == 1) {
            for (i = T; i <= B; i++)
                result.push_back(A[i][R]);
            dir++; R--;
        } else if (dir == 2) {
            for (i = R; i >=L; i--)
                result.push_back(A[B][i]);
            dir++; B--;
        } else if (dir == 3) {
            for (i = B; i >= T; i--)
                result.push_back(A[i][L]);
            dir++; L++;
        }
        dir = dir % 4;
    }
    
    return result;
}
