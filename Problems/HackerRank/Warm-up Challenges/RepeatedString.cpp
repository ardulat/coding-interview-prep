// https://www.hackerrank.com/challenges/repeated-string/

#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long ans = 0;
    long full = n / s.size();
    if (full != 0) {
        for (int i = 0; i < s.size(); i++)
            if (s[i] == 'a')
                ans++;
        ans = ans * full;
    }
    long partial = n % s.size();
    if (partial != 0)
        for (int i = 0; i < partial; i++)
            if (s[i] == 'a')
                ans++;
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

