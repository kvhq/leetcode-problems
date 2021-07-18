// Number: 57
// Name: Insert Interval
// Tags: greedy

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        for (int i = 0; i < intervals.size(); ++i) {
            vector<int> curInt = intervals[i];
            if (curInt[1] < newInterval[0])
                answer.push_back(curInt);
            else if (curInt[0] > newInterval[1]) {
                answer.push_back(newInterval);
                answer.insert(answer.end(), intervals.begin() + i, intervals.end());
                return answer;
            } else if (newInterval[0] >= curInt[0] && newInterval[1] <= curInt[1])
                return intervals;
            else if (newInterval[0] < curInt[0] && newInterval[1] > curInt[1])
                continue;
            else if (newInterval[0] <= curInt[0] && newInterval[1] <= curInt[1])
                newInterval[1] = curInt[1];
            else if (newInterval[0] >= curInt[0] && newInterval[1] >= curInt[1])
                newInterval[0] = curInt[0];	
        }
        answer.push_back(newInterval);
        return answer;
    }

};

