// Number: 76
// Name: Minimum Window Substring
// Tags: Sliding Window

// ugly O(N * M) solution
class Solution_0 {
public:
    bool isMatched(unordered_map<char, int>& data, unordered_map<char, int>& pattern, pair<int, int>& answer_p, int lhs, int rhs) {
        for (const auto& x : pattern) {
            if (data.find(x.first) == data.end()) return false;
            if (data[x.first] < x.second) return false;
        }
        if (answer_p.first == -1) answer_p = make_pair(lhs, rhs);
        else if (answer_p.second - answer_p.first > rhs - lhs) answer_p = make_pair(lhs, rhs);
        return true;
    }
    
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        unordered_map<char, int> pattern;
        for (const auto& x : t) pattern[x]++;
        int lhs = 0;
        pair<int, int> answer_p = make_pair(-1, -1);
        unordered_map<char, int> window;
        for (int rhs = 0; rhs < s.size(); ++rhs) {
            if (window.empty() && pattern.find(s[rhs]) != pattern.end())
                window[s[rhs]]++;
            else if (!window.empty())
                window[s[rhs]]++;
            if (isMatched(window, pattern, answer_p, lhs, rhs)) {
                window[s[lhs]]--;
                if (window[s[lhs]] == 0) window.erase(s[lhs]);
                lhs++;
                while (pattern.find(s[lhs]) == pattern.end() && lhs < s.size() || isMatched(window, pattern, answer_p, lhs, rhs)) {
                    window[s[lhs]]--;
                    if (window[s[lhs]] == 0) window.erase(s[lhs]);
                    lhs++;
                }
            }
            isMatched(window, pattern, answer_p, lhs, rhs);
        }
        if (answer_p.first == -1) return "";
        string answer;
        for (int i = answer_p.first; i <= answer_p.second; ++i)
            answer += s[i];
        return answer;
    }
};

// pretty O(N + M)


