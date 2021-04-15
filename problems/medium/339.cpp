// Number: 339
// Name: Nested List Weight Sum
// Tag: DFS

class Solution_1 {
public:
    void dive(const NestedInteger& nestInt, int depth, int& answer) {
        if (nestInt.isInteger()) answer += nestInt.getInteger() * depth;
        else {
            depth++;
            for (const auto& x : nestInt.getList()) dive(x, depth, answer);
        }
    }

    int depthSum(vector<NestedInteger>& nestedList) {
        int depth = 1;
        int answer = 0;
        for (const auto& x : nestedList) {
            dive(x, depth, answer);
        }
        return answer;
    }
};

class Solution_2 {
public:
    int dive(vector<NestedInteger>& list, int depth) {
        int total = 0;
        for (auto& x : list) {
            if (x.isInteger()) total += x.getInteger() * depth;
            else total += dive(x.getList(), depth + 1);
        }
        return total;
    }

    int depthSum(vector<NestedInteger>& nestedList) {
        return dive(nestedList, 1);
    }
};

