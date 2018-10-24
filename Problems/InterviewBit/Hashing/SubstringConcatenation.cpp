// https://www.interviewbit.com/problems/substring-concatenation/

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    unordered_map<string,int> hashmap;
    for (auto word : B) {
        if (hashmap.find(word) == hashmap.end()) // not present
            hashmap[word] = 0;
        hashmap[word]++;
    }
    int word_length = B[0].size(); // all are of equal length
    int K = B.size()*word_length; // substring size
    int i = 0;
    vector<int> result;
    while (i+K <= A.size()) {
        string substring = A.substr(i, K); // substring
        unordered_map<string,int> temp_hashmap = hashmap; // copy constructor
        int j = 0;
        while (j < K) {
            string word = substring.substr(j, word_length); // word
            if (temp_hashmap.find(word) == temp_hashmap.end()) // not present
                break;
            else
                temp_hashmap[word]--;
            j += word_length;
        }
        bool isSubstring = true;
        for (auto& pair : temp_hashmap) {
            string word = pair.first;
            if (temp_hashmap[word] > 0) {
                isSubstring = false;
                break;
            }
        }
        if (isSubstring)
            result.push_back(i);
        i++;
    }
    return result;
}
