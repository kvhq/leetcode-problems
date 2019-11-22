vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int,int> freqElement;
    vector<int> answer;
    for (const auto& x : nums1) {
        if (freqElement.count(x) == 0) {
            freqElement[x]++;
        }
    }
    for (const auto& x : nums2) {
        if (freqElement.count(x) != 0) {
            if (freqElement[x] == 1) {
                answer.push_back(x);
                freqElement[x]++;
            }
        }
    }
    return answer;
}
