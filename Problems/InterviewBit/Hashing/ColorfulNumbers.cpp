// https://www.interviewbit.com/problems/colorful-number/

// Note: we can insert key, value pair to unordered_map (C++)
// in the same way as to dict (Python): a[key] = value;

int Solution::colorful(int A) {
    unordered_map<int, bool> ht;
    string str = to_string(A);
    for (int i = 0; i < str.size(); i++) {
        int multiplication = 1;
        for (int j = i; j < str.size(); j++) {
            multiplication *= (int)(str[j]-'0');
            if (ht.find(multiplication) != ht.end())
                return 0;
            ht[multiplication] = true;
        }
    }
    return 1;
}
