// Number: 1762
// Name: Buildings With an Ocean View
// Tags: vector, stack

// O(N) , O(1)
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int curHighest = 0;
        vector<int> answer;
        for (int i = heights.size() - 1; i >= 0; --i) {
            if (answer.empty() || heights[i] > heights[answer.back()])
                answer.push_back(i);
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};

