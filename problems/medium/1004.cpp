// Number: 1004
// Name: Max Consecutive Ones III
// Tags: sliding window

// using set. Time O(N) ; Space O(K)
class Solution_0 {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lhs = 0;
        unordered_set<int> data;
        int answer = 0;
        for (int rhs = 0; rhs < nums.size(); ++rhs) {
            if (nums[rhs] == 0) data.insert(rhs);
            while (data.size() > k) {
                if (data.find(lhs) != data.end()) data.erase(lhs);
                lhs++;
            }
            answer = max(answer, rhs - lhs + 1);
        }
        return answer;
    }
};

// time O(N) ; Space O(1)
class Solution_1 {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lhs = 0;
        int answer = 0;
        for (int rhs = 0; rhs < nums.size(); ++rhs) {
            if (nums[rhs] == 0) k--;
            while (k < 0) {
                if (nums[lhs] == 0) k++;
                lhs++;
            }
            answer = max(answer, rhs - lhs + 1);
        }
        return answer;
    }
};

