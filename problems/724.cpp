int pivotIndex(vector<int>& nums) {
    int sum = 0;
    for (auto& x : nums) {
        sum += x;
    }
    int temp = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (temp == sum - temp - nums[i]) {
            return i;
        }
        temp += nums[i];
    }
    return -1;
}