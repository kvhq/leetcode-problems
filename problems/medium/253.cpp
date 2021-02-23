// number: 253
// name: Meeting Rooms 2
// tags: sorting

int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    vector<pair<int, int>> timeline;
    for (const auto& x : intervals) {
        timeline.push_back(make_pair(0, x[0])); // begin
        timeline.push_back(make_pair(1, x[1])); // end
    }
    sort(timeline.begin(), timeline.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
        if (lhs.second == rhs.second) return lhs.first > rhs.first;
        return lhs.second < rhs.second;
    });
    int rooms_total = 1;
    int rooms_taken = 0;
    for (const auto& x : timeline) {
        if (x.first == 0) {
            if (rooms_taken != rooms_total) {
                rooms_taken++;
            } else {
                rooms_total++;
                rooms_taken++;
            }
        } else rooms_taken--;
    }
    return rooms_total;
}

