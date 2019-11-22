vector<string> commonCharsBadVersion(vector<string>& A) {
    vector<string> answer;

    unordered_map<char,pair<int,int>> bigFreqMap;

    for (const auto& str : A) {
        unordered_map<char, int> charFreq;
        for (const auto& ch : str) {
            charFreq[ch]++;
        }
        for (auto& x : charFreq) {
            if (bigFreqMap.count(x.first) == 0) {
                bigFreqMap[x.first] = make_pair(1, x.second);
            } else {
                bigFreqMap[x.first].first++;
                if (x.second < bigFreqMap[x.first].second) {
                    bigFreqMap[x.first].second = x.second;
                }
            }
        }
    }

    for (auto& x : bigFreqMap) {
        if (x.second.first == A.size()) {
            for (int i = 0; i < x.second.second; ++i) {
                string temp = "";
                temp += x.first;
                answer.push_back(temp);
            }
        }
    }
    return answer;
}


