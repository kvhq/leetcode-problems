// Number: 238
// Name: Move Zeroes
// Tags: array, two pointers

void moveZeroes(vector<int>& nums) {
    int f_z = -1;
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (nums[i] == 0) {
            if (f_z == -1) f_z = i;
        }
        else if (f_z != -1) {
            swap(nums[f_z], nums[i]);
            f_z++;
        }
    }

