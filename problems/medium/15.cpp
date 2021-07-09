// Number: 15
// Name: 3Sum
// Tags: two pointer

// sort and two pointer, O(n*logn + n^2) -> O(n^2)
// space O(1)
class Solution {
public:
    void findTriplets(const vector<int>& nums, vector<vector<int>>& answer, int lhs, int targetSum) {
        int rhs = nums.size() - 1;
        while (lhs < rhs) {
            int curSum = nums[lhs] + nums[rhs];
            if (curSum == targetSum) {
                answer.push_back({-targetSum, nums[lhs], nums[rhs]});
                lhs++;
                rhs--;
                while (lhs < rhs && nums[lhs] == nums[lhs - 1]) lhs++;
                while (lhs < rhs && nums[rhs] == nums[rhs + 1]) rhs--;
            } else if (curSum > targetSum) rhs--;
            else lhs++;
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            findTriplets(nums, answer, i + 1, -nums[i]);
        }
        return answer;
    }
};

// sort, hash table O(N^2)
class Solution {
public:
    void findTriplets(const vector<int>& nums, vector<vector<int>>& answer, int lhs) {
        unordered_set<int> seen;
        for (int j = lhs + 1; j < nums.size(); ++j) {
            int toComplete = -nums[lhs] - nums[j];
            if (seen.count(toComplete)) {
                answer.push_back({nums[lhs], nums[j], toComplete});
                while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                    ++j;
            }
            seen.insert(nums[j]);
        }
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[i - 1])
                findTriplets(nums, answer, i);
        }
        return answer;
    }
};
