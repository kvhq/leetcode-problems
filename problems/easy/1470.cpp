//Number: 1470
//Name: Shuffle the Array
//Tags: array

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> answer(2*n);
        for(size_t i = 0; i < n; ++i) {
            answer[2 * i] = nums[i];
            answer[2 * i + 1] = nums[n + i];
        }
        return answer;
    }
};

