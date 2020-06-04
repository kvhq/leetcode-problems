// Number: 3
// Name: Longest Substring Without Repeating Characters
// Tags: sliding window, string, hash table

int lengthOfLongestSubstring(string s) {
    if (s.size() == 0) return 0;
    unordered_map<char, int> d;
    d[s[0]] = 0;
    int start = 0;
    int cur_len = 1;
    int ans = 1;
    for (int i = 1; i < (int)s.size(); ++i) {
        char cur_c = s[i];
        if (d.find(cur_c) == d.end()) {
            d[cur_c] = i;
            cur_len++;
            if (cur_len > ans) ans = cur_len;
        }
        else {
            if (d[cur_c] + 1 > start) start = d[cur_c] + 1;
            d[cur_c] = i;
            cur_len = i - start + 1;
            if (cur_len > ans) ans = cur_len;
        }
    }
    if (cur_len > ans) ans = cur_len;
    return ans;
}

