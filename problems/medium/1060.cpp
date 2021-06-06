// Number: 1060
// Name: Missing Element in Sorted Array
// Tags: array, binary search

// O(log(N)) O(1) ugly solution
class Solution_0 {
public:
    int missingElement(vector<int>& nums, int k) {
        int lhs = 0;
        int rhs = nums.size() - 1;
        while (rhs - lhs > 1) {
            int mid = lhs + (rhs - lhs) / 2;
            int missed_total = nums[mid] - (nums[lhs] + mid - lhs);
            if (missed_total >= k) rhs = mid;
            else {
                k -= missed_total;
                lhs = mid;
            }
        }
        if (nums[rhs] - nums[lhs] > k) return nums[lhs] + k;
        return k + nums[lhs] + 1;
    }
};

// O(log(N)) O(1) pretty solution


