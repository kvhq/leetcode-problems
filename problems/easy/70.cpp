// Number: 70
// Name: Climbing Stairs
// Tags: DP

// brute force
class Solution_0 {
public:
    int climbStairs(int n) {
        if (n == 0) return 1;
        int answer = 0;
        for (int i = 1; i <= 2; ++i) {
            if (n - i >= 0) answer += climbStairs(n - i);
        }
        return answer;
    }
};

// DP top-down
class Solution_1 {
public:
    int helper(int i_n, vector<int>& i_cache) {
        if (i_n == 0) return 1;
        int answer = 0;
        for (int i = 1; i <= 2; ++i) {
            if (i_n - i >= 0) {
                if (i_cache[i_n - i] != -1) answer += i_cache[i_n - i];
                else {
                    answer += helper(i_n - 1, i_cache);
                    i_cache[i_n - i] = answer;
                }
            }
        }
        return answer;
    }
    
    int climbStairs(int n) {
        vector<int> cache(n, -1);
        int answer = helper(n, cache);
        return answer;
    }
};

// bottom-up
class Solution_2 {
public:
    int climbStairs(int n) {
        vector<int> cache(n + 1, -1);
        cache[0] = 1;
        for (int i = 1; i <= n; ++i) {
            if (cache[i] == -1) {
                int cur_combs = 0;
                for (int j = 1; j <= 2; ++j) {
                    if (i - j >= 0) cur_combs += cache[i - j];
                }
                cache[i] = cur_combs;
            }
        }
        return cache.back();
    }
};

// O(1) memory
class Solution_3 {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; ++i) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};

