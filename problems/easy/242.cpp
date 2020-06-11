// Number: 242
// Name: Valid Anagram
// Tags: hash table, string

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, int> d;
    for (int i = 0; i < s.size(); ++i) {
        d[s[i]]++;
        d[t[i]]--;
    }
    for (const auto& p : d) {
        if (p.second != 0) return false;
    }
    return true;
}

