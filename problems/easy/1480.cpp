//Number: 1480
//Name: Running Sum of 1d Array
//Tags: array

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for (size_t i = 1; i < nums.size(); ++i) {
            nums[i] = nums[i] + nums[i - 1];
        }
        return nums;
    }
};

