vector<int> findDisappearedNumbers(vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
        if (nums[i] == i + 1) {
            i++;
            continue;
        }
        else if (nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
            continue;
        }
        else {
            i++;
        }
    }
    vector<int> answer;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != i + 1) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}
