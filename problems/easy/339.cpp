// Number: 339
// Name: Nested List Weight Sum
// Tags: DFS

void traverseNestedList(const NestedInteger& n_l, int lvl, int& sum) {
    if (n_l.isInteger()) {
        sum += n_l.getInteger()*lvl;
    } else {
        for (const auto& n : n_l.getList()) {
            traverseNestedList(n, lvl + 1, sum);
        }
    }
    return;
}

int depthSum(vector<NestedInteger>& nestedList) {
    int sum = 0;
    int cur_lvl = 1;
    for (const auto& n : nestedList) {
        traverseNestedList(n, cur_lvl, sum);
    }
    return sum;
}

