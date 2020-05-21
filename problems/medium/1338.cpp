// Number: 1338
// Name: Reduce Array Size to The Half
// Tags: array, greedy

int minSetSize(vector<int>& arr) {
    unordered_map<int, int> freq;
    for (const auto& x : arr) {
        freq[x]++;
    }
    priority_queue<int> pq;
    for (const auto& x : freq) {
        pq.push(x.second);
    }
    int answer = 0;
    int deleted_amount = 0;
    while (deleted_amount < (int)(arr.size() / 2)) {
        answer += 1;
        deleted_amount += pq.top();
        pq.pop();
    }
    return answer;
}

