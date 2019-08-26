//first come up with
void moveZeroes(vector<int>& nums) {
    if (nums.size() == 1) {
        return;
    }
    int check = 0;
    int compare = check + 1;
    while (check < nums.size()) {
        compare = check + 1;
        if (nums[check] == 0) {
            for (int i = compare; i < nums.size(); i++) {
                if (nums[i] != 0) {
                    swap(nums[check], nums[i]);
                    break;
                }
            }
        }
        check++;
    }
}
//good one
void moveZeroes(vector<int>& nums) {
    for(int i = 0, j = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[j] = nums[i];
            if (i != j) {
                nums[i] = 0;
            }
            j++;
        }
    }
}
