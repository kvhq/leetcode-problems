// Number: 953
// Name: Verifying an Alien Dictionary
// Tags: string

class Solution {
public:
    bool compareWords(const string& s1, const string& s2, const unordered_map<char, int>& dict) {
        int len = min(s1.size(), s2.size());
        for (int i = 0; i < len; ++i) {
            int p_s1 = dict.at(s1[i]);
            int p_s2 = dict.at(s2[i]);
            if (p_s1 != p_s2) return p_s1 < p_s2;
        }
        if (s1.size() > s2.size()) return false;
        return true;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        if (words.size() == 1) return true;
        unordered_map<char, int> dict;
        for (int i = 0; i < order.size(); ++i)
            dict[order[i]] = i;
        for (int i = 0; i < words.size() - 1; ++i)
            if(!compareWords(words[i], words[i + 1], dict)) return false;
        return true;
    }
};

