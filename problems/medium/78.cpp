// Number: 78
// Name: Subsets
// Tags: recursion, backtracking

class Solution_0 {
public:
    void helper(const vector<int>& nums, int curIndex, vector<int> curSet, vector<vector<int>>& answer) {
        if (curIndex == nums.size()) {
            answer.push_back(curSet);
            return;
        }
        helper(nums, curIndex + 1, curSet, answer);
        curSet.push_back(nums[curIndex]);
        helper(nums, curIndex + 1, curSet, answer);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        helper(nums, 0, {}, answer);
        return answer;
    }
};

// less memory - only O(N)
class Solution {
public:
    void helper(const vector<int>& nums, int curIndex, vector<int>& curSet, vector<vector<int>>& answer) {
        answer.push_back(curSet);
        for (int i = curIndex; i < nums.size(); ++i) {
            curSet.push_back(nums[i]);
            helper(nums, i + 1, curSet, answer);
            curSet.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> curSet = {};
        helper(nums, 0, curSet, answer);
        return answer;
    }
};

