// Number: 977
// Name: Squares of a Sorted Array
// Tags: array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        int lhs = 0;
        int rhs = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            int square = 0;
            if (abs(nums[lhs]) < abs(nums[rhs])) {
                square = nums[rhs];
                rhs--;
            } else {
                square = nums[lhs];
                lhs++;
            }
            answer[i] = square * square;
        }
        return answer;
    }
};

