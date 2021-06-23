// Number: 3
// Name: Longest Substring Without Repeating Characters
// Tags: sliding window, string, hash table

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> data;
        int lhs = 0;
        int answer = 0;
        for (int rhs = 0; rhs < s.size(); ++rhs) {
            int curElem = s[rhs];
            data[curElem]++;
            while (data[curElem] > 1) {
                data[s[lhs]]--;
                if (data[s[lhs]] == 0) data.erase(s[lhs]);
                lhs++;
            }
            answer = max(answer, (int)data.size());
        }
        return answer;
    }
};

