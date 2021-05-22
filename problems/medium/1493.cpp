// Number: 1493
// Name: Longest Subarray of 1's After Deleting One Element
// Tags: array, sliding window

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int answer = 0;
        int prevLength = 0;
        int curLength = 0;
        int zeroDistance = 0;
        bool wasDeleted = false;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                curLength++;
                zeroDistance = 0;
            } else {
                answer = max(answer, prevLength + curLength);
                if (!wasDeleted) wasDeleted = true;
                if (zeroDistance == 0) prevLength = curLength;
                else prevLength = 0;
                curLength = 0;
                zeroDistance++;
            }
        }
        answer = max(answer, prevLength + curLength);
        if (!wasDeleted) return --answer;
        return answer;
    }
};

