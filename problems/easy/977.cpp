// Number: 977
// Name: Squares of a Sorted Array
// Tags: array

public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        int lhs = 0;
        int rhs = n - 1;
        int curPos = n - 1;
        while (lhs <= rhs) {
            if (abs(nums[rhs]) >= abs(nums[lhs])) answer[curPos--] = nums[rhs] * nums[rhs--];
            else answer[curPos--] = nums[lhs] * nums[lhs++];
        }
        return answer;
    }
};
