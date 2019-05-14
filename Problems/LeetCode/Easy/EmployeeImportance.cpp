// https://leetcode.com/problems/employee-importance/

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    Employee* getEmployee(vector<Employee*> employees, int id) {
        Employee* wanted;
        for (Employee* x : employees) {
            if (x->id == id) {
                wanted = x;
                break;
            }
        }
        return wanted;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        int count = 0;
        queue<int> q;
        q.push(id); // add parent node
        while (!q.empty()) {
            int temp = q.front(); // retrieve node
            q.pop(); // remove node
            Employee* emp = getEmployee(employees, temp);
            count += emp->importance;
            if (!(emp->subordinates).empty())
                for (int x : emp->subordinates)
                    q.push(x);
        }
        return count;
    }
};