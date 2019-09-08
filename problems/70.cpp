int helpFunc(int floor, int hight, vector<int>& memo) {
    if (floor > hight) {
        return 0;
    }
    if (floor == hight) {
        return 1;
    }
    if (memo[floor] > 0) {
        return memo[floor];
    }
    memo[floor] = helpFunc(floor + 1, hight, memo) + helpFunc(floor + 2, hight, memo);
    return memo[floor];
}

int climbStairs(int n) {
    vector<int> memo(n);
    return helpFunc(0, n, memo);
}
