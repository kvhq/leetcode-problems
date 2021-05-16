// Number: 139
// Name: Word Break
// Tags: DP

// DP top-down, O(nˆ3) time because of substr
class Solution_1 {
public:
    bool helper(string s, vector<string>& wordDict, vector<int>& data, int fromIndex) {
        if (s == "") return true;
        string tempString = "";
        bool answer = false;
        for (int i = 0; i < s.size(); ++i) {
            tempString += s[i];
            if (find(wordDict.begin(), wordDict.end(), tempString) != wordDict.end()) {
                if (fromIndex + i == data.size()) return true;
                if (data[fromIndex + i] == -1)
                    data[fromIndex + i] = helper(s.substr(i + 1), wordDict, data, fromIndex + i);
                answer = data[fromIndex + i] ? true : answer;
            }
        }
        return answer;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> data(s.size(), -1);
        return helper(s, wordDict, data, 1);
    }
};

// brute force
class Solution_0 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s == "") return true;
        string tempString = "";
        bool answer = false;
        for (int i = 0; i < s.size(); ++i) {
            tempString += s[i];
            if (find(wordDict.begin(), wordDict.end(), tempString) != wordDict.end()) {
                answer = wordBreak(s.substr(i + 1), wordDict) ? true : answer;
            }
        }
        return answer;
    }
};

// DP bottom-up
class Solution_2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> data(s.size() + 1);
        data[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; j++) {
                if (data[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    data[i] = true;
                    break;
                }
            }
        }
        return data[s.size()];
    }
};


