/*
- we could go with a naive approach but I would like to try Rabin-Karp algorithm with hashing the sliding window
- hash function for Rabin-Karp:
    hash = (d * hash + str[i]) % q, where d - number of characters in alphabet, q - prime number
- to calculate hash value of the next window:
    hash = (d(hash – txt[s]*h ) + txt[s+m]) mod q, where h = d^(m-1) % q
*/
int strStr(string haystack, string needle) {
    int hash_haystack = 0; // empty in the beginning
    int hash_pattern = 0; // empty in the beginning
    int m = needle.length();
    int n = haystack.length();
    int d = 26; // obly lowercase English-alphabet characters
    int q = 23; // prime number chosen
    int h = 1;
    
    // step 1: calculate h
    for (int i = 0; i < m-1; i++)
        h = (d * h) % q;
    
    // step 2: calculate hash values of the first window and pattern/needle
    for (int i = 0; i < m; i++) {
        hash_haystack = (d * hash_haystack + haystack[i]) % q;
        hash_pattern = (d * hash_pattern + needle[i]) % q;
    }
    
    // step 3: compare hashes
    for (int i = m; i <= n; i++) { // start is always at (i-m)
        if (hash_haystack == hash_pattern) {
            // step 4: compare character by character
            int j;
            for (j = 0; j < m; j++) {
                if (haystack[i-m+j] != needle[j])
                    break;
            }
            // step 5: pattern found, return starting index
            if (j == m)
                return i-m;
        }
        // step 6: update hash of the window
        hash_haystack = (d * (hash_haystack - haystack[i-m]*h) + haystack[i]) % q;
        
        if (hash_haystack < 0) // hash may be negative
            hash_haystack += q;
    }
    
    return -1;
}