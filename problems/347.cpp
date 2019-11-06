vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freqMap;
    for (const auto& x : nums) {
        freqMap[x]++;
    }
    vector<int> answer;
    priority_queue<pair<int, int>> pq;
    for (const auto& x : freqMap) {
        pq.push(make_pair(x.second, x.first));
    }
    for (int i = 0; i < k; ++i) {
        answer.push_back(pq.top().second);
        pq.pop();
    }
    return answer;
}
