// Number: 39
// Name: Combination Sum
// Tags: backtracking

// time O(N^(T/M)) where T - target, M - minimal number
// space O(T/M)
class Solution {
public:
    void helper(vector<int>& nums, vector<int>& comb, int target, vector<vector<int>>& answer, int index) {
        if (target == 0) answer.push_back(comb);
        else {
            for (int i = index; i < nums.size() && target - nums[i] >= 0; ++i) {
                comb.push_back(nums[i]);
                helper(nums, comb, target - nums[i], answer, i);
                comb.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        vector<int> curComb = {};
        helper(candidates, curComb, target, answer, 0);
        return answer;
    }
};

