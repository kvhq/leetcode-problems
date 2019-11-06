void putNumber(vector<vector<int>>& ans, vector<int>& v, vector<bool>& helper,
              const vector<int>& nums) {
    if (v.size() == nums.size()) {
        ans.push_back(v);
    } else {
        for (int i = 0; i < nums.size(); ++i) {
            if (helper[i] == false) {
                v.push_back(nums[i]);
                helper[i] = true;
                putNumber(ans, v, helper, nums);
                helper[i] = false;
                v.pop_back();
            }
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> answerVector;
    vector<int> tempVec;
    vector<bool> stats(nums.size(), false);
    putNumber(answerVector, tempVec, stats, nums);
    return answerVector;
}
