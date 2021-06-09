// Number: 487
// Name: Max Consecutive Ones II
// Tags: array

// time O(N) space O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curMax = 0;
        int prevLen = 0;
        int curLen = 0;
        int seenZero = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                seenZero = 1;
                prevLen = curLen;
                curLen = 0;
            }
            else curLen++;
            curMax = max(curMax, prevLen + curLen + seenZero);
        }
        return curMax;
    }
};

