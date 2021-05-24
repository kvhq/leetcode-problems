// Number: 40
// Name: Combination Sum II
// Tags: backtracking

// time O(2ˆN) space O(N)
class Solution {
public:
    void helper(vector<int>& nums, int target, vector<int>& curComb, vector<vector<int>>& answer, int index) {
        if (target == 0) answer.push_back(curComb);
        else {
            for (int i = index; i < nums.size() && target >= nums[i]; ++i) {
                if (i == index || nums[i] != nums[i - 1]) {
                    curComb.push_back(nums[i]);
                    helper(nums, target - nums[i], curComb, answer, i + 1);
                    curComb.pop_back();
                }
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        vector<int> curComb;
        helper(candidates, target, curComb, answer, 0);
        return answer;
    }
};

