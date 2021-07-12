// Number: 414
// Name: Third Maximum Number
// Tags: array

// O(N) time; O(1) space
class Solution {
public:
    void findUnseenMax(const vector<int>& nums, set<int>& seen) {
        bool meet = false;
        int curMax = 0;
        for (const auto& x : nums) {
            if (!meet && seen.count(x) == 0) {
                curMax = x;
                meet = true;
            }
            else if (x > curMax && seen.count(x) == 0) curMax = x;
        }
        if (meet) seen.insert(curMax);
        return;
    }
    
    int thirdMax(vector<int>& nums) {
        set<int> seen_maxs;
        for (int i = 0; i < 3; ++i)
            findUnseenMax(nums, seen_maxs);
        if (seen_maxs.size() < 3) return *rbegin(seen_maxs);
        return *begin(seen_maxs);
    }
};

