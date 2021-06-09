// Number: 27
// Remove Element
// Tags: array

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lhs = 0;
        for (int rhs = 0; rhs < nums.size(); ++rhs) {
            if (nums[rhs] != val) {
                nums[lhs] = nums[rhs];
                lhs++;
            }
        }
        return lhs;
    }
};

