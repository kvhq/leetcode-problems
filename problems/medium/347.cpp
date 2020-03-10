// Number: 347
// Name: Top K Frequent Elements
// Tags: array, map, heap

// using map + unordered_map
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> numToFreq;
    // O(n)
    for (const auto& x : nums) {
        if (numToFreq.find(x) != numToFreq.end()) {
            numToFreq[x]++;
        } else numToFreq[x] = 1;
    }
    map<int, vector<int>> freqToNums;
    // O(n)
    for (const auto& p : numToFreq) {
        if (freqToNums.find(p.second) != freqToNums.end()) {
            freqToNums[p.second].push_back(p.first);
        } else {
            vector<int> t{p.first};
            freqToNums[p.second] = t;
        }
    }
    vector<int> answer;
    for (auto iter = freqToNums.rbegin(); iter != freqToNums.rend(); ++iter) {
        if (iter->second.size() < k) {
            answer.insert(answer.end(), iter->second.begin(), iter->second.end());
            k -= iter->second.size();
        } else {
            answer.insert(answer.end(), iter->second.begin(), iter->second.begin() + k);
            return answer;
        }
        if (k <= 0) return answer;
    }
    return answer;
}

// using unordered_map and min_heap
class Comp {
    public:
        int operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first > p2.first;
        }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> numToFreq;
    for (const auto& x : nums) {
        if (numToFreq.find(x) != numToFreq.end()) {
            numToFreq[x]++;
        } else numToFreq[x] = 1;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> minHeap;
    vector<int> answer;
    for (const auto& x : numToFreq) {
        minHeap.push(make_pair(x.second, x.first));
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    for (int i = 0; i < k; ++i) {
        answer.push_back(minHeap.top().second);
        maxHeap.pop();
    }

    return answer;
}
