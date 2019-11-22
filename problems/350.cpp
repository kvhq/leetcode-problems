vector<int> intersectVersion1(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> freqElement;
    vector<int> answer;
    for (const auto& x : nums1) {
        freqElement[x]++;
    }
    for (const auto& x : nums2) {
        if (freqElement.count(x) != 0) {
            if (freqElement[x] > 0) {
                answer.push_back(x);
                freqElement[x]--;
            }
        }
    }
    return answer;
}

vector<int> intersectVersion2(vector<int>& nums1, vector<int>& nums2) {
    vector<int> answer;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0;
    int j = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            answer.push_back(nums1[i]);
            j++;
            i++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        }
    }
    return answer;
}
