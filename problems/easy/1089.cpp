// array

// O(N) space (worst case), if N = number_of_zeros
void duplicateZeros(vector<int>& arr) {
    queue<int> helper;
    for (auto& x : arr) {
        if (helper.size() == 0) {
            if (x != 0) {
                continue;
            } else {
                helper.push(0);
            }
        } else {
            helper.push(x);
            if (x == 0) {
                helper.push(x);
            }
            x = helper.front();
            helper.pop();
        }
    }
    return;
}
