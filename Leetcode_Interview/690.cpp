/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution
{

    /*Tree BFS: Since we can travel a node from exactly one parent, there is no need to check if a node has already been travelled or not time complexity O(E) but edges in tree=nodes = O(n)*/
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        map<int, Employee *> mp; //maping id with index
        for (int i = 0; i < employees.size(); i++)
        {
            int id = employees[i]->id;
            mp[id] = employees[i];
        }
        queue<int> q;
        q.push(id);
        int sum = 0;
        while (!q.empty())
        {
            int parent = q.front();
            q.pop();
            Employee *employee = mp[parent];
            sum += employee->importance;
            for (int elem : employee->subordinates)
            {
                q.push(elem);
            }
        }
        return sum;
    }
};