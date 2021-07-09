// Number: 16
// Name: 3Sum Closest
// Tags: Two Pointer

// time O(n^2) space (N)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minSum = INT_MAX;
        int minDiff = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int rhs = nums.size() - 1;
            int lhs = i + 1;
            while (lhs < rhs) {
                int curSum = nums[lhs] + nums[rhs] + nums[i];
                if (abs(target - curSum) < minDiff) {
                    minDiff = abs(target - curSum);
                    minSum = curSum;
                } else if (minDiff == abs(target - curSum))
                    minSum = min(minSum, curSum);
                if (curSum > target)
                    rhs--;
                else if (curSum < target)
                    lhs++;
                else return curSum;
            }
        }
        return minSum;
    }
};

