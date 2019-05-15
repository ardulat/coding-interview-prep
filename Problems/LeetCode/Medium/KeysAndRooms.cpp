// https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    /*    
    [[1,3],[-1,-1,-1],[2],[-1]]
    */
    
    void dfs(vector<vector<int>>& rooms, int id) {
        // cout << "Entering room #" << id << endl;
        for (int i = 0; i < rooms[id].size(); i++)
            if (rooms[id][i] != -1) {
                int temp = rooms[id][i];
                rooms[id][i] = -1; // mark as visited
                dfs(rooms, temp);
            }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(rooms, 0);
        for (vector<int>& room : rooms)
            for (int key : room)
                if (key != -1)
                    return false;
        return true;
    }
};