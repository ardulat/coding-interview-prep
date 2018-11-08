// https://leetcode.com/problems/encode-and-decode-tinyurl/

class Solution {
private:
    unordered_map<string, string> longToShort;
    unordered_map<string, string> shortToLong;
    int count;
    string alphabet = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (longToShort.find(longUrl) != longToShort.end())
            return longToShort[longUrl];
        // encode
        count++;
        int num = count;
        string shortUrl = "";
        // ensure
        cout << "alphabet size: " << alphabet.size() << endl;
        while (num > 0) {
            shortUrl += alphabet[num % 62];
            num = num / 62;
        }
        
        cout << "shortUrl: " << shortUrl << endl;
        
        longToShort[longUrl] = shortUrl;
        shortToLong[shortUrl] = longUrl;
        
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        cout << "longUrl: " << shortToLong[shortUrl] << endl;
        return shortToLong[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));