// Number: 368
// Name: Largest Divisible Subset
// Tags: dynamic programming

vector<int> largestDivisibleSubset(vector<int>& nums) {
    if (nums.size() == 0) return {};
    int n = (int)nums.size();
    sort(nums.begin(), nums.end());
    vector<int> maxDiv(n, 1);
    vector<int> prevNum(n, -1);
    int maxPos = 0;

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && maxDiv[i] < maxDiv[j] + 1) {
                maxDiv[i] = maxDiv[j] + 1;
                prevNum[i] = j;
            }
        }
        if (maxDiv[i] > maxDiv[maxPos]) {
            maxPos = i;
        }
    }

    vector<int> answer;
    int p = maxPos;
    while(p >= 0) {
        answer.push_back(nums[p]);
        p = prevNum[p];
    }

    return answer;
}

