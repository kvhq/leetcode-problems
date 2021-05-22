// Number: 690
// Name: Employee Importance
// Tags: hashmap, queue

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        if (employees.empty()) return 0;
        unordered_map<int, Employee*> data;
        for (const auto& x : employees) {
            data[x->id] = x;
        }
        queue<Employee*> q;
        q.push(data[id]);
        int answer = 0;
        while (!q.empty()) {
            Employee* curEmp = q.front();
            q.pop();
            answer += curEmp->importance;
            for (const auto& x : curEmp->subordinates) {
                q.push(data[x]);
            }
        }
        return answer;
    }
};

