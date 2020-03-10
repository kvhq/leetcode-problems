// Number: 1
// Name: Two Sum
// Tags: hash table

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> dict;
    vector<int> answer;
    for (int i = 0; i < nums.size(); ++i) {
        if (dict.find(target - nums[i]) != dict.end()) {
            answer.push_back(i);
            answer.push_back(dict[target - nums[i]]);
            return answer;
        } else {
            dict[nums[i]] = i;
        }
    }
    return answer;
}

