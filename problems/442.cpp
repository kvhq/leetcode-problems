vector<int> findDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return nums;
    }
    vector<int> answerList;
    for(int i = 0; i < nums.size();) {
        if (nums[i] == i + 1) {
            i++;
        } else if (nums[i] != nums[nums[i] - 1]){
            swap(nums[i], nums[nums[i] - 1]);
        } else {
            i++;
        }
    }
    for(int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i + 1) {
            answerList.push_back(nums[i]);
        }
    }
    return answerList;
}
