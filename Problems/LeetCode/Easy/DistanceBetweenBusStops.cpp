// https://leetcode.com/problems/distance-between-bus-stops/

class Solution {
public:
    /*
    Brute-force: O(N)
    - check clockwise and counter clockwise
    */
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        
        int clockwise = 0;
        int i = start;
        while (i != destination) {
            clockwise += distance[i];
            i++;
            i = i % n;
        }
        
        int counterclockwise = 0;
        i = destination;
        while (i != start) {
            counterclockwise += distance[i];
            i++;
            i = i % n;
        }
        
        return min(clockwise, counterclockwise);
    }
};