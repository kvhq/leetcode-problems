// Number: 387
// Name: First Unique Character in a String
// tag: string, hash table

int firstUniqChar(string s) {
    unordered_map<char,int> dict;
    for (const auto& ch : s)
	dict[ch]++;
    for (int i = 0; i < s.size(); ++i) {
        if (dict[s[i]] == 1)
            return i;
    }
    return -1;
}
