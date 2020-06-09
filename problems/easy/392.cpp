// Number: 392
// Name: Is Subsequence
// Tags: string, trie, binary search

bool isSubsequence(string s, string t) {
    if (s.size() == 0) return true;
    if (t.size() < s.size()) return false;
    for (int i = 0, j = 0; i < s.size(), j < t.size();) {
        if (t.size() - j < s.size() - i) return false;
        if (s[i] == t[j]) {
            i++;
            j++;
            if (i == s.size()) return true;
        } else {
            j++;
        }
    }
    return false;
}

