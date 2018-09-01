// https://www.hackerrank.com/challenges/counting-valleys/

#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int height = 0, valleys = 0, prevHeight;
    
    for (int i = 0; i < n; i++) {
        prevHeight = height;
        if (s[i] == 'D')
            height--;
        else
            height++;
        
        if (height == 0 && prevHeight < 0)
            valleys++;
    }
    
    return valleys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

