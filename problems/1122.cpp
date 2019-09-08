vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> arr2Map;
    vector<int> others;
    vector<int> answer;
    for (const auto& x : arr2) {
        arr2Map[x] = 0;
    }
    for (const auto& x : arr1) {
        if (arr2Map.count(x) > 0) {
            arr2Map[x]++;
        }
        else {
            others.push_back(x);
        }
    }
    for (const auto& x : arr2) {
        for (int i = 0; i < arr2Map[x]; ++i) {
            answer.push_back(x);
        }
    }
    sort(others.begin(), others.end());
    for (const auto& x : others) {
        answer.push_back(x);
    }
    return answer;
}
