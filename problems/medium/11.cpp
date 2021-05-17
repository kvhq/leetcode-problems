// Number: 11
// Name: Container With Most Water
// Tags: two pointer

class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0;
        int lhs = 0;
        int rhs = height.size() - 1;
        while (lhs < rhs) {
            answer = max(answer, min(height[lhs], height[rhs]) * (rhs - lhs));
            if (height[lhs] < height[rhs]) lhs++;
            else rhs--;
        }
        return answer;
    }
};

