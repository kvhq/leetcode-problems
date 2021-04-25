// Number: 53
// Name: Maximum Subarray
// Tags: array, two pointer, dp

int maxSubArray(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    int answer = nums[0];
    int cur_sum = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        if (cur_sum < 0) cur_sum = nums[i];
        else cur_sum += nums[i];
        answer = max(answer, cur_sum);
    }
    answer = max(answer, cur_sum);
    return answer;
}

