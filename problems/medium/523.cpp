// Number: 523
// Name: Continuous Subarray Sum
// Tags: array, set

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() == 1) return false;
        unordered_set<int> data;
        int sum = 0;
        int prev = 0;
        for (int i = 0; i != nums.size(); ++i) {
            sum += nums[i];
            sum = sum % k;
            if (data.find(sum) != data.end()) return true;
            data.insert(prev);
            prev = sum;
        }
        return false;
    }
};

