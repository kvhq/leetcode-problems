// Number: 239
// Name: Sliding Window Maximum
// Tags: sliding window, priority queue, heap, DP

// priority queue; time O(N * logN) space O(N)
class Solution_0 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq; // (value, index)
        vector<int> answer;
        for (int i = 0; i < k; ++i) pq.push(make_pair(nums[i], i));
        answer.push_back(pq.top().first);
        for (int i = k; i < nums.size(); ++i) {
            pq.push(make_pair(nums[i], i));
            while (true) {
                auto candidate = pq.top();
                if (candidate.second > i - k) {
                    answer.push_back(candidate.first);
                    break;
                } else pq.pop();
            }
        }
        return answer;
    }
};

// deque; time O(N) space O(k)
class Solution_1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;
        deque<int> windowIndexes;
        vector<int> answer;
        for (int left = 0; left < nums.size(); ++left) {
            if (windowIndexes.front() == left - k) windowIndexes.pop_front();
            while (!windowIndexes.empty() && nums[windowIndexes.back()] < nums[left]) windowIndexes.pop_back();
            windowIndexes.push_back(left);
            if (left - k + 1 >= 0) answer.push_back(nums[windowIndexes.front()]);
        }
        return answer;
    }
};


