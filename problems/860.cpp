bool lemonadeChange(vector<int>& bills) {
    vector<int> money = {0,0,0};
    for (const auto& p : bills) {
        if (p == 5) {
            money[0] += 1;
        } else if (p == 10) {
            money[1] += 1;
            money[0] -= 1;
        } else if (p == 20) {
            if (money[1] > 0 && money[0] > 0) {
                money[1] -= 1;
                money[0] -= 1;
            } else if (money[0] > 2) {
                money[0] -= 3;
            } else {
                return false;
            }
        }
        if (money[0] < 0 || money[1] < 0 || money[2] < 0) {
            return false;
        }
    }
    return true;
}
