// https://leetcode.com/problems/exclusive-time-of-functions/

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> time(n, 0);
        stack<int> ids;
        for (string log : logs) {
            // step 1: parse log
            int i = 0;
            string id = "";
            while (log[i] != ':') {
                id += log[i];
                i++;
            }
            int idx = stoi(id);
            i++; // skip ":"
            string op = ""; // start or end
            while (log[i] != ':') {
                op += log[i];
                i++;
            }
            i++; // skip ":"
            string tp = ""; // timestamp (string)
            while (i < log.length()) {
                tp += log[i];
                i++;
            }
            int timestamp = stoi(tp);
            
            // step 2: perform action
            if (op == "start") {
                if (!ids.empty()) {
                    int prev = ids.top();
                    time[prev] = timestamp+time[prev];
                }
                time[idx] = time[idx] - timestamp;
                ids.push(idx);
            } else { // op == "end"
                ids.pop(); // ids are the same because CPU is single threaded
                time[idx] = timestamp+time[idx]+1;
                if (!ids.empty()) {
                    int prev = ids.top();
                    time[prev] = time[prev]-timestamp-1;
                }
            }
        }
        return time;
    }
};