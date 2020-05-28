// Number: 438
// Name: Find All Anagrams in a String
// Tags: hash table, sliding window

vector<int> findAnagrams(string s, string p) {
    unordered_map<char, int> d;
    for (const auto& x : p) {
        d[x]++;
    }
    int p_s = (int)p.size();
    int s_s = (int)s.size();
    vector<int> ans;
    for (int i = 0; i < p_s; ++i) {
        if (d.find(s[i]) != d.end()) {
            d[s[i]]--;
        }
    }
    bool isOK = true;
    for (const auto& x : d) {
        if (x.second != 0) isOK = false;
    }
    if (isOK) ans.push_back(0);
    else isOK = true;
    for (int i = 1; i <= s_s - p_s; ++i) {
        if (d.find(s[i - 1]) != d.end()) d[s[i - 1]]++;
        if (d.find(s[i + p_s - 1]) != d.end()) d[s[i + p_s - 1]]--;
        for (const auto& x : d) {
            if (x.second != 0) isOK = false;
        }
        if (isOK) ans.push_back(i);
        else isOK = true;
    }
    return ans;
}

