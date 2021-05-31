// Number: 238
// Name: Product of Array Except Self
// Tags: array

// O(3*N) = O(N) ; O(2*N) = O(N)
class Solution_0 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> leftMults(n, 1);
        vector<int> rightMults(n, 1);
        for (int i = 0; i < nums.size() - 1; ++i) {
            leftMults[i + 1] = nums[i] * leftMults[i];
        }
        
        for (int i = nums.size() - 2; i >= 0; --i) {
            rightMults[i] = rightMults[i + 1] * nums[i + 1];
        }
        for (size_t i = 0; i < n; ++i) {
            nums[i] = leftMults[i] * rightMults[i];
        }
        return nums;
    }
};

// O(N) ; O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t n = nums.size();
        vector<int> rightMults(n, 1);
        for (int i = nums.size() - 2; i >= 0; --i) {
            rightMults[i] = rightMults[i + 1] * nums[i + 1];
        }
        int left = 1;
        for (size_t i = 0; i < n; ++i) {
            rightMults[i] = left * rightMults[i];
            left *= nums[i];
        }
        return rightMults;
    }
};

