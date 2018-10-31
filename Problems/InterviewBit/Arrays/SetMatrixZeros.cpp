// https://www.interviewbit.com/problems/set-matrix-zeros/

void Solution::setZeroes(vector<vector<int> > &A) {
    int i, j;
    bool setColumn = false, setRow = false;
    
    // traverse first row
    for (i = 0; i < A.size(); i++)
        if (A[i][0] == 0) {
            setRow = true;
            break;
        }
    // traverse first column
    for (i = 0; i < A[0].size(); i++)
        if (A[0][i] == 0) {
            setColumn = true;
            break;
        }
    // traverse matrix starting from the second column and row
    for (i = 0; i < A.size(); i++)
        for (j = 0; j < A[0].size(); j++)
            if (A[i][j] == 0) {
                A[0][j] = 0;
                A[i][0] = 0;
            }
    // set the appropriate columns and rows to 0
    for (i = 1; i < A.size(); i++) {
        if (A[i][0] == 0)
            for (j = 1; j < A[0].size(); j++)
                A[i][j] = 0;
    }
    for (j = 1; j < A[0].size(); j++) {
        if (A[0][j] == 0)
            for (i = 1; i < A.size(); i++)
                A[i][j] = 0;
    }
    // set first column and row to zero if needed
    if (setRow)
        for (i = 0; i < A.size(); i++)
            A[i][0] = 0;
    if (setColumn)
        for (j = 0; j < A[0].size(); j++)
            A[0][j] = 0;
}
