// https://leetcode.com/problems/invalid-transactions/submissions/

class Solution {
    struct Transaction {
        string original;
        
        string name;
        int time;
        int amount;
        string city;
        
        Transaction(string o, string n, int t, int a, string c) {
            original = o;
            name = n;
            time = t;
            amount = a;
            city = c;
        }// original(o), name(n), time(t), amount(a), city(c) {}
    };
    
public:
    Transaction parse(string str) {
        int i = 0, n = str.size();
        
        string name = "";
        while (str[i] != ',') {
            name += str[i];
            i++;
        }
        
        i++;
        string timeStr = "";
        while (str[i] != ',') {
            timeStr += str[i];
            i++;
        }
        
        int time = stoi(timeStr);
        
        i++;
        string amountStr = "";
        while (str[i] != ',') {
            amountStr += str[i];
            i++;
        }
        
        int amount = stoi(amountStr);
        // cout << amount << endl;
        
        i++;
        string city = "";
        while (i < n) {
            city += str[i];
            i++;
        }
        
        Transaction *res = new Transaction(str, name, time, amount, city);
        // cout << res->name << " " << res->time << " " << res->amount << " " << res->city << endl;
        
        return *res;
    }
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<Transaction> parsed;
        
        for (string t : transactions)
            parsed.push_back(parse(t));
        
        unordered_set<string> res;
        
        for (int i = 0; i < n; i++) {
            bool isInvalid = false;
            
            for (int j = i+1; j < n; j++) {
                if (parsed[i].name == parsed[j].name
                    && abs(parsed[i].time - parsed[j].time) <= 60
                    && parsed[i].city != parsed[j].city) {
                    
                    isInvalid = true;
                    res.insert(parsed[j].original);
                }
            }
            // cout << parsed[i].amount << endl;
            if (isInvalid || parsed[i].amount > 1000)
                res.insert(parsed[i].original);
        }
        
        vector<string> ans;
        
        for (string r : res)
            ans.push_back(r);
        
        return ans;
    }
};

/*
- define a class/struct for storing each transaction
- write out (parse) all transactions and store in array of transactions type
- traverse transactions array twice to find required transactions
*/