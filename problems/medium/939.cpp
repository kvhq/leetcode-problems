// Number: 939
// Name: Minimum Area Rectangle
// Tags: hashmap, set

// ugly with 2 sets. O(N*N) ; O(N)
class Solution_1 {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> x_map;
        unordered_map<int, unordered_set<int>> y_map;
        for (const auto& x : points) {
            if (x_map.find(x[0]) != x_map.end()) x_map[x[0]].insert(x[1]);
            else {
                unordered_set<int> tempSet;
                tempSet.insert(x[1]);
                x_map[x[0]] = tempSet;
            }
            if (y_map.find(x[1]) != y_map.end()) y_map[x[1]].insert(x[0]);
            else {
                unordered_set<int> tempSet;
                tempSet.insert(x[0]);
                y_map[x[1]] = tempSet;
            }
        }
        int answer = 0;
        for (const auto& x1 : x_map) {
            if (x1.second.size() < 2) continue;
            for (const auto& x1_y1 : x1.second) {
                // now we visit each x2 in x1_y1 map
                if (y_map[x1_y1].size() < 2) continue;
                for (const auto& x2 : y_map[x1_y1]) {
                    if (x2 == x1.first) continue;
                    if (x_map[x2].size() < 2) continue;
                    for (const auto& x2_y2 : x_map[x2]) {
                        if (x2_y2 == x1_y1) continue;
                        if (x1.second.find(x2_y2) != x1.second.end()) {
                            int tempArea = abs(x1.first - x2) * abs(x2_y2 - x1_y1);
                            if (answer == 0) answer = tempArea;
                            else answer = min(answer, tempArea);
                        }
                    }
                }
            }
        }
        return answer;
    }
};

// better, 1 hashmap ; O(N*N) ; O(N)
class Solution_1 {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, set<int>> data;
        int res = 0;
        for (const auto& p : points) data[p[0]].insert(p[1]);
        for (auto i = data.begin(); i != data.end(); ++i) {
            for (auto j = next(i); j != data.end(); ++j) {
                if (i->second.size() < 2 || j->second.size() < 2) continue;
                vector<int> y;
                set_intersection(begin(i->second), end(i->second),
                                 begin(j->second), end(j->second),
                                 back_inserter(y));
                for (int k = 1; k < y.size(); ++k)
                    if (res == 0) res = abs(i->first - j->first) * (y[k] - y[k - 1]);
                    else res = min(res, abs(i->first - j->first) * (y[k] - y[k - 1]));
            }
        }
        return res;
    }
};

