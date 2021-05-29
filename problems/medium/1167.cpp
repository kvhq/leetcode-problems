// Number: 1167
// Name: Minimum Cost to Connect Sticks
// Tags: priority queue

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        if (sticks.size() == 1) return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto& x : sticks) pq.push(x);
        int answer = 0;
        while (pq.size() != 1) {
            int curTop = pq.top();
            pq.pop();
            int secondTop = pq.top();
            pq.pop();
            int newStick = curTop + secondTop;
            answer += newStick;
            pq.push(newStick);
        }
        return answer;
    }
};

