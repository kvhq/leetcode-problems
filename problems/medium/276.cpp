// Number: 276
// Name: Paint Fence
// Tags: dynamic programming

// brute force
class Solution_0 {
public:
    int helper(int n, int k, int prevColor, int whatWasBefore) {
        if (n == 0) return 1;
        int combinations = 0;
        for (int i = 1; i <= k; ++i) {
            if (i != prevColor) combinations += helper(n - 1, k, i, 0);
            else if (whatWasBefore != i) combinations += helper(n - 1, k, i, i);
        }
        return combinations;
    }
    
    int numWays(int n, int k) {
        return helper(n, k, 0, 0);
    }
};

// DP


