// Number: 713
// Name: Subarray Product Less Than K
// Tags: sliding window

// O(N^2)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int answer = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int rhs = i + 1;
            int curProd = nums[i];
            if (curProd < k) answer++;
            else continue;
            while (rhs < nums.size()) {
                curProd *= nums[rhs];
                if (curProd < k) answer++;
                else break;
                rhs++;
            }
        }
        return answer;
    }
};

//

