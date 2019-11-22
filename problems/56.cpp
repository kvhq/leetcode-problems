vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) {
        return intervals;
    }
    vector<vector<int>> answer;
    sort(intervals.begin(), intervals.end(),
        [](const auto& l, const auto& r){
            return l[0] < r[0];});
    vector<int> tempVector = intervals[0];
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] > tempVector[1]) {
            answer.push_back(tempVector);
            tempVector = intervals[i];
        } else if (intervals[i][1] > tempVector[1]) {
            tempVector[1] = intervals[i][1];
        }
    }
    answer.push_back(tempVector);
    return answer;
}
