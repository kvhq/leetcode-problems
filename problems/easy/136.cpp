// Number: 136
// Name: Single Number
// Tags: Math, Bit Manipulation

int singleNumber(vector<int>& nums) {
    map<int,int> freqMap;
    for (const auto& x : nums) {
        freqMap[x]++;
    }
    for (const auto& x : freqMap) {
        if (x.second == 1) {
            return x.first;
        }
    }
    return 0;
}

//should be done one more solution
//using bit manipulation

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int answer = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            answer ^= nums[i];
        }
        return answer;
    }
};

