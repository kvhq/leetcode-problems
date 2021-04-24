//Number: 1086
//Name: High Five
//Tags: sort, array, hashmap, heap

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, vector<int>> data;
        vector<vector<int>> answer;
        for (const auto& x : items) {
            if (data.find(x[0]) != data.end()) data[x[0]].push_back(x[1]);
            else data[x[0]] = {x[1]};
        }
        for (auto& x : data) {
            sort(x.second.begin(), x.second.end(), [](const auto& a, const auto& b) { return a > b; });
        }
        for (const auto& x : data) {
            int score = 0;
            for (int i = 0; i < 5; ++i) {
                score += x.second[i];
            }
            answer.push_back({x.first, score / 5});
        }
        return answer;
    }
};

