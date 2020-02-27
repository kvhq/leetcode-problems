// greedy

vector<int> replaceElements(vector<int>& arr) {
    if (arr.size() == 0) {
        return arr;
    }
    int s = arr.size();
    int curMax = arr[s - 1];
    arr[s - 1] = -1;
    for (int i = s - 2; i >= 0; --i) {
        int temp = curMax;
        if (arr[i] > curMax) {
            curMax = arr[i];
            arr[i] = temp;
        } else {
            arr[i] = curMax;
        }
    }
    return arr;
}
