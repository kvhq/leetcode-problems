// Number: 383
// Name: Ransom Note
// Tags: hashmap

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ransomeMap;
        for (const auto& x : magazine)
            ransomeMap[x]++;
        for (const auto& x : ransomNote) {
            ransomeMap[x]--;
            if (ransomeMap[x] < 0) return false;
        }
        return true;
    }
};

