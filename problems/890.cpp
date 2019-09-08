vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    unordered_map<char, vector<int>> m;
    for (int i = 0; i < pattern.size(); ++i) {
        m[pattern[i]].push_back(i);
    }
    set<vector<int>> pSet;
    for (const auto& x : m) {
        pSet.insert(x.second);
    }
    vector<string> answer;
    for (const auto& x : words) {
        unordered_map<char, vector<int>> tM;
        for (int i = 0; i < x.size(); ++i) {
            tM[x[i]].push_back(i);
        }
        set<vector<int>> tSet;
        for (const auto& y : tM) {
            tSet.insert(y.second);
        }
        if (tSet == pSet) {
            answer.push_back(x);
        }
    }
    return answer;
}