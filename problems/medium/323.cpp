// Number: 323
// Name: Number of Connected Components in an Undirected Graph
// Tags: tree, dfs, union

// DFS
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> nodes(n);
        unordered_map<int, vector<int>> data;
        for (const auto& x : edges) {
            if (data.find(x[0]) != data.end()) data[x[0]].push_back(x[1]);
            else data[x[0]] = {x[1]};
            if (data.find(x[1]) != data.end()) data[x[1]].push_back(x[0]);
            else data[x[1]] = {x[0]};
        }
        int answer = 0;
        int i = 0;
        stack<int> st;
        while (i < n) {
            if (nodes[i] == 0) {
                answer++;
                if (data.find(i) != data.end()) {
                    st.push(i);
                    while (!st.empty()) {
                    int cur_node = st.top();
                    st.pop();
                    nodes[cur_node] = 1;
                    if (data.find(cur_node) != data.end())
                        for (const auto& x : data[cur_node]) 
                            if (nodes[x] != 1) st.push(x);
                    }
                }
            }
            i++;
        }
        return answer;
    }
};

