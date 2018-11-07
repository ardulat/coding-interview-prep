// https://leetcode.com/problems/merge-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool compareIntervals(const Interval& interval1, const Interval& interval2) {
        return interval1.start < interval2.start;
    }
    
    // bool operator < (Interval i1, Interval i2) {
    //     return i1.start < i2.start;
    // }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        int n = intervals.size();
        
        // base case:
        if (n == 0)
            return result;
        
        sort(intervals.begin(), intervals.end(), compareIntervals);

        stack<Interval> s;
        s.push(intervals[0]);

        for (int i = 1; i < n; i++) {
            Interval top = s.top();
            if (top.end < intervals[i].start)
                s.push(intervals[i]);
            else if (top.end < intervals[i].end) {
                s.pop();
                top.end = intervals[i].end;
                s.push(top);
            }
        }

        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }

        return result;
    }
};