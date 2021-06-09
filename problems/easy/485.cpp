// Number: 485
// Name: Max Consecutive Ones
// Tags: array

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curMax = 0;
        int curLen = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                curMax = max(curMax, curLen);
                curLen = 0;
            } else curLen++;
        }
        curMax = max(curMax, curLen);
        return curMax;
    }
};

