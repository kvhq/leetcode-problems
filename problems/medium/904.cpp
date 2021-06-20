// Number: 904
// Name: Fruit Into Baskets
// Tags: two pointers

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int answer = 0;
        int lhs = 0;
        unordered_map<int, int> data;
        for (int rhs = 0; rhs < tree.size(); ++rhs) {
            data[tree[rhs]]++;
            while (data.size() > 2) {
                data[tree[lhs]]--;
                if (data[tree[lhs]] == 0) data.erase(tree[lhs]);
                lhs++;
            }
            int curSum = 0;
            for (const auto& x : data) curSum += x.second;
            answer = max(answer, curSum);
        }
        return answer;
    }
};

