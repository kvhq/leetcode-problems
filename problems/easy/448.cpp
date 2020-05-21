// Number: 448
// Name: Find All Numbers Disappeared in an Array
// Tags: array

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

// new iteration solution
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> answer;
    for (int i = 0; i < (int)nums.size();) {
        if (nums[i] != i + 1) {
            if (nums[i] != nums[nums[i] - 1]) 
                swap(nums[i], nums[nums[i] - 1]);
            else i++;
        } else i++;
    }
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (nums[i] != i + 1) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}
