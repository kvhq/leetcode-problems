// Number: 905
// Name: Sort Array By Parity
// Tags: array, two pointers


// time O(N) space O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int lhs = 0;
        int rhs = nums.size() - 1;
        while (lhs < rhs) {
            if (nums[lhs] % 2 > nums[rhs] % 2) {
                swap(nums[lhs], nums[rhs]);
            }
            if (nums[lhs] % 2 == 0) lhs++;
            if (nums[rhs] % 2 == 1) rhs--;
        }
        return nums;
    }
};

