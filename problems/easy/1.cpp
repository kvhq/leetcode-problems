//Number: 1
//Name: Two Sum
//Tags: hash table, array

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> data;
    for (int i = 0; i < nums.size(); ++i) {
        if (data.find(target - nums[i]) != data.end()) return {i, data[target - nums[i]]};
        else data[nums[i]] = i;
    }
    return {};
}

