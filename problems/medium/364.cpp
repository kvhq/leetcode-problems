// Number: 364
// Name: Nested List Weight Sum II
// Tags: DFS

class Solution_1 {
public:
    void dfs(vector<NestedInteger>& list, int depth, int& maxDepth) {
        if (depth > maxDepth) maxDepth = depth;
        for (auto& x : list) {
            if (!x.isInteger()) dfs(x.getList(), depth + 1, maxDepth);
        }
    }

    int dive(vector<NestedInteger>& list, int depth, int maxDepth) {
        int total = 0;
        for (auto& x : list) {
            if (x.isInteger()) total += x.getInteger() * (maxDepth - depth + 1);
            else total += dive(x.getList(), depth + 1, maxDepth);
        }
        return total;
    }

    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxD = 0;
        dfs(nestedList, 1, maxD);
        return dive(nestedList, 1, maxD);
    }
};

class Solution_2 {
public:
    void dive(vector<NestedInteger>& list, int depth, int& maxDepth, vector<pair<int,int>>& d) {
        if (depth > maxDepth) maxDepth = depth;
        for (auto& x : list) {
            if (x.isInteger()) d.push_back(make_pair(x.getInteger(), depth));
            else dive(x.getList(), depth + 1, maxDepth, d);
        }
    }

    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<pair<int,int>> data;
        int maxD = 0;
        int answer = 0;
        dive(nestedList, 1, maxD, data);
        for (const auto& x : data) {
            answer += x.first * (maxD - x.second + 1);
        }
        return answer;
    }
};

