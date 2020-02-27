// greedy

int balancedStringSplit(string s) {
    if (s.size() == 0) {
        return 0;
    }
    int amount = 0;
    int counter_L = 0;
    int counter_R = 0;
    for (const auto& x : s) {
        if (x == 'R') {
            counter_R++;
        } else {
            counter_L++;
        }
        if (counter_R == counter_L) {
            amount++;
            counter_R = 0;
            counter_L = 0;
        }
    }
    return amount;
}
