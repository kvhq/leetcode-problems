// Number: 266
// Name: Palindrome Permutation
// Tags: array, hashmap

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> data;
        for (const auto& x : s) {
            if (data.find(x) != data.end()) {
                if (data[x] == 0) data[x]++;
                else data[x]--;
            } else data[x] = 1;
        }
        bool wasMiddle = false;
        for (const auto& x : data) {
            if (x.second > 1) return false;
            if (x.second == 1) {
                if (!wasMiddle) wasMiddle = true;
                else return false;
            }
        }
        return true;
    }
};

