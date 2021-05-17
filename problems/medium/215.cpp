// Number: 215
// Name: Kth Largest Element in an Array
// Tags: array

// basic, just sort O(nlogn)
class Solution_0 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

// using partial sort
class Solution_1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), std::greater<int>());
        return nums[k - 1];
    }
};

