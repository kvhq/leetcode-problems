// Name: Single Number
// Tags: hash map, bit manipulation

// via hash map
int singleNumber(vector<int>& nums) {
    map<int,int> dict;
    for (const auto& x : nums) {
        dict[x]++;
    }
    for (const auto& x : dict) {
        if (x.second == 1) {
            return x.first;
        }
    }
    return -1;
}

// via bit manipulation
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        ans ˆ= nums[i];
    }
    return ans;
}
