// https://leetcode.com/problems/queue-reconstruction-by-height/

class Solution {
public:
    /*
    Brute-force: O(N^2)
    - sort in descending order of height
    - for each element in sorted array:
        - put/insert in people[i][1] position (by k)
    */
    struct comparator {
        bool operator() (const vector<int> first, const vector<int> second) {
            if (first[0] == second[0])
                return first[1] < second[1];
                
            return first[0] > second[0];
        }
    };
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comparator()); // O(NlogN)
        
        // for (vector<int> pr : people)
        //     cout << "["<< pr[0] << "," << pr[1] << "]" << endl;
        
        vector<vector<int>> res;
        for (vector<int> pr : people) { // O(N) time
            int pos = pr[1];
            res.insert(res.begin() + pos, pr); // O(N) time
        }
        
        return res;
    }
};