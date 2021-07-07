// Number: 259
// Name: 3Sum Smaller
// Tags: two pointer

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        int answer = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] + nums[i + 1] + nums[i + 2] >= target) break;
            int lhs = i + 1;
            int rhs = nums.size() - 1;
            while (lhs < rhs) {
                int curSum = nums[i] + nums[lhs] + nums[rhs];
                if (curSum < target) {
                    answer += (rhs - lhs);
                    lhs++;
                } else if (curSum >= target)
                    rhs--;
            }
        }
        return answer;
    }
};

