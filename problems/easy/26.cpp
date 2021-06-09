// Number: 26
// Name: Remove Duplicates from Sorted Array
// Tags: array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int lhs = 0;
        for (int rhs = 1; rhs < nums.size(); ++rhs) {
            if (nums[rhs] != nums[lhs]) {
                nums[++lhs] = nums[rhs];
            }
        }
        return lhs + 1;
    }
};

