// Number: 451
// Name: Sort Characters By Frequency
// Tags: hast table, string

string frequencySort(string s) {
    unordered_map<char,int> dict;
    string answer;
    for (const auto& ch : s) {
        if (dict.find(ch) == dict.end()) {
            dict[ch] = 1;
        } else dict[ch]++;
    }
    map<int,vector<char>> freq_dict;
    for (const auto& p : dict) {
        if (freq_dict.find(p.second) == freq_dict.end()) {
            vector<char> newVec{p.first};
            freq_dict[p.second] = newVec;
        } else freq_dict[p.second].push_back(p.first);
    }
    for (auto iter = freq_dict.rbegin(); iter != freq_dict.rend(); ++iter) {
        for (const auto& l : iter->second) {
            answer += string(iter->first, l);
        }
    }
    return answer;
}
