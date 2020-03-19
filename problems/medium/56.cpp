// Number: 56
// Name: Merge Intervals
// Tags: sort, greedy

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](
    const vector<int> lhs, const vector<int> rhs) {
        return lhs[0] < rhs[0];
    });
    vector<vector<int>> answer;
    int numInters = intervals.size();
    for (int i = 0; i < numInters; ++i) {
        if (i == numInters - 1) {
            answer.push_back(intervals[i]);
            break;
        }
        vector<int> interval;
        int curStart = intervals[i][0];
        int curEnd = intervals[i][1];
        interval.push_back(curStart);
        for (int j = i + 1; j < numInters; ++j) {
            if (intervals[j][0] > curEnd) break;
            i++;
            if (intervals[j][1] > curEnd) {
                curEnd = intervals[j][1];
            }
        }
        interval.push_back(curEnd);
        answer.push_back(interval);
    }
    return answer;
}
