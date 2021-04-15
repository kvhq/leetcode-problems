// Number:340
// Name: Longest Substring with At Most K Distinct Characters
// Tags: sliding window, string

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        if (s.size() == 1) return 1;
        int start_index = 0;
        int max_len = 1;
        unordered_map<char, int> data;
        data[s[0]] = 0;
        int cur_d = 1;
        for (int i = 1; i < (int)s.size(); ++i) {
            if (data.find(s[i]) == data.end()) {
                if (cur_d < k) {
                    data[s[i]] = i;
                    cur_d++;
                } else {
                    cur_d++;
                    while (cur_d > k) {
                        if (data[s[start_index]] == start_index) {
                            data[s[start_index]] = -1;
                            cur_d--;
                        }
                        start_index++;
                    }
                    data[s[i]] = i;
                }
            } else {
                if (data[s[i]] != -1) data[s[i]] = i;
                else {
                    if (cur_d < k) {
                        cur_d++;
                        data[s[i]] = i;
                    } else {
                        cur_d++;
                        while (cur_d > k) {
                            if (data[s[start_index]] == start_index) {
                                data[s[start_index]] = -1;
                                cur_d--;
                            }
                            start_index++;
                        }
                        data[s[i]] = i;
                    }
                }
            }
            max_len = max(max_len, i - start_index + 1);
        }
        return max_len;
    }
};

