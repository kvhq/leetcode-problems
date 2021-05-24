// Number: 252
// Name: Meeting Rooms
// Tags: sort, array

// sorting. O(n*log(n) + n) ; O(1)
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return true;
        sort(intervals.begin(), intervals.end(), [](const auto& lhs, const auto& rhs){
            return lhs[0] < rhs[0];
        });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i - 1][1]) return false;
        }
        return true;
    }
};

