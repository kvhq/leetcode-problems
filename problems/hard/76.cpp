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

// ugly O(N + M)
class Solution {
public:
    string minWindow(string s, string t) {
        string answer = "";
        int ans_lhs = -1;
        int ans_rhs = -1;
        unordered_map<char, int> t_data;
        for (const auto& x : t) t_data[x]++;
        unordered_map<char, int> seen;
        int matched = 0;
        int lhs = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (t_data.find(s[i]) != t_data.end() && lhs == -1) {
                // we found new substring, so set lhs to its start and update seen
                lhs = i;
                seen[s[i]]++;
                if (seen[s[i]] == t_data[s[i]]) matched++;
            } else if (t_data.find(s[i]) != t_data.end() && lhs != -1) {
                // we continue already found substring
                seen[s[i]]++;
                if (seen[s[i]] == t_data[s[i]]) matched++;
            }
            // here we make a check if it is correct substring
            while (matched == t_data.size() && lhs < s.size()) {
                if (i - lhs < ans_rhs - ans_lhs || ans_rhs == -1) {
                    ans_lhs = lhs;
                    ans_rhs = i;
                }
                seen[s[lhs]]--;
                if (seen[s[lhs]] < t_data[s[lhs]]) matched--;
                lhs++;
                while (lhs <= i && t_data.find(s[lhs]) == t_data.end())
                       lhs++;
            }
        }
        if (ans_rhs != -1) {
            for (int i = ans_lhs; i <= ans_rhs; ++i)
                answer += s[i];
        }
        
        return answer;
    }
};

