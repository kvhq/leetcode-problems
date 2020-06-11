// Number: 75
// Name: Sort Colors
// Tags: array, pointers

void sortColors(vector<int>& nums) {
    int r_s = 0;
    int w_s = 0;
    int b_s = (int)nums.size() - 1;
    while (w_s <= b_s) {
        if (nums[w_s] == 0) {
            swap(nums[w_s], nums[r_s]);
            w_s++;
            r_s++;
        } else if (nums[w_s] == 2) {
            swap(nums[w_s], nums[b_s]);
            b_s--;
        } else w_s++;
    }
    return;
}

