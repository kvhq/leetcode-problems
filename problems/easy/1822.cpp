// Number: 1822
// Name: Sign of the Product of an Array
// Tags: Math

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int totalMinuses = 0;
        for (const auto& x : nums) {
            if (x == 0) return 0;
            if (x < 0) totalMinuses++;
        }
        if (totalMinuses % 2 == 0) return 1;
        return -1;
    }
};

