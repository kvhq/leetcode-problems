// Number: 1051
// Name: Height Checker
// Tags: array

// sort, O(N log N) ; O(N)
class Solution_0 {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> compare = heights;
        sort(compare.begin(), compare.end());
        int answer = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (heights[i] != compare[i]) answer++;
        }
        return answer;
    }
};

// counting sort, O(N) ; O(N);
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> data(101, 0);
        for (const auto& x : heights)
            data[x]++;
        int answer = 0;
        int curHeight = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (data[curHeight] == 0) curHeight++;
            if (curHeight != heights[i]) answer++;
            data[curHeight]--;            
        }
        return answer;
    }
};

