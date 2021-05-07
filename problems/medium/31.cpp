// Number: 31
// Name: Next Permutation
// Tags: array

class Solution {
public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
        return;
    }
    
    void reverse(vector<int>& nums, int lhs, int rhs) {
        while (lhs <= rhs) {
            swap(nums[lhs], nums[rhs]);
            lhs++;
            rhs--;
        }
        return;
    }
    
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        int n = nums.size();
        for (int i = n - 1; i > 0;) {
            if (nums[i] <= nums[i - 1]) --i;
            else {
                for (int j = n - 1; j >= i; --j) {
                    if (nums[j] > nums[i - 1]) {
                        swap(nums[j], nums[i - 1]);
                        reverse(nums, i, n - 1);
                        return;
                    }
                }
            }
        }
        reverse(nums, 0, n - 1);
        return;
    }
};

