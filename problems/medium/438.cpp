// Number: 438
// Name: Find All Anagrams in a String
// Tags: hash table, sliding window

class Solution {
public:
    bool isMatched(const vector<int>& v1, const vector<int>& v2) {
        if (v1 != v2) return false;
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        vector<int> p_data(26);
        vector<int> window(26);
        vector<int> answer;
        for (int i = 0; i < p.size(); ++i) {
            p_data[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size() - p.size(); ++i) {
            if (isMatched(p_data, window)) answer.push_back(i);
            window[s[p.size() + i] - 'a']++;
            window[s[i] - 'a']--;
        }
        if (isMatched(p_data, window)) answer.push_back(s.size() - p.size());
        return answer;
    }
};

