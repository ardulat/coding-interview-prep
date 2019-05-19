// https://leetcode.com/problems/find-duplicate-file-in-system/

class Solution {
public:
    /*
    Algorithm:
    - create hashtable of type string mapped to vector of strings
    - retrieve full path of each file
    - retrieve its content
    - add each content to full paths
    - if key in hashtable has more than 1 element in array, then it is duplicate
    - put the value of that key to resultant array
    */
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string,vector<string>> content2path;
        for (string path : paths) {
            int i = 0;
            string dir = ""; // root directory path
            while (path[i] != ' ') {
                dir += path[i];
                i++;
            }
            i++; // space
            string name = "", content = "";
            bool copyName = true, copyContent = false; // flags
            while (i < path.size()) {
                if (path[i] == '(') {
                    copyName = false;
                    i++; // '('
                    copyContent = true;
                }
                if (copyName)
                    name += path[i];
                if (path[i] == ')')
                    copyContent = false;
                if (copyContent)
                    content += path[i];
                
                if (path[i] == ' ' || i+1 == path.size()) { // next word starts
                    string fullPath = dir+'/'+name;
                    content2path[content].push_back(fullPath);
                    name = "";
                    content = "";
                    copyName = true;
                    copyContent = false;
                }
                i++;
            }
        }
        
        vector<vector<string>> result;
        for (auto& row : content2path)
            if (row.second.size() > 1) // duplicate
                result.push_back(row.second);
        
        return result;
    }
};