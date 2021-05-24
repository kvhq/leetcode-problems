// Number: 674
// Name: Longest Continuous Increasing Subsequence
// Tags: array

// time O(n) ; space O(1)
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int curMax = 1;
        int curLength = 1;
        if (nums.size() == 1) return 1;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) curLength++;
            else {
                curMax = max(curMax, curLength);
                curLength = 1;
            }
        }
        curMax = max(curMax, curLength);
        return curMax;
    }
};

