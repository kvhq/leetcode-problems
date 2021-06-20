// Number: 451
// Name: Sort Characters By Frequency
// Tags: hast table, string

// ugly
string frequencySort(string s) {
    unordered_map<char,int> dict;
    string answer;
    for (const auto& ch : s) {
        if (dict.find(ch) == dict.end()) {
            dict[ch] = 1;
        } else dict[ch]++;
    }
    map<int,vector<char>> freq_dict;
    for (const auto& p : dict) {
        if (freq_dict.find(p.second) == freq_dict.end()) {
            vector<char> newVec{p.first};
            freq_dict[p.second] = newVec;
        } else freq_dict[p.second].push_back(p.first);
    }
    for (auto iter = freq_dict.rbegin(); iter != freq_dict.rend(); ++iter) {
        for (const auto& l : iter->second) {
            answer += string(iter->first, l);
        }
    }
    return answer;
}

// better O(nlogn)
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counterData;
        for (const auto& x : s)
            counterData[x]++;
        vector<pair<char, int>> sortData(counterData.begin(), counterData.end());
        sort(sortData.begin(), sortData.end(), [](const auto& lhs, const auto& rhs){
           return lhs.second > rhs.second; 
        });
        string answer = "";
        for (const auto& x : sortData) {
            for (int i = 0; i < x.second; ++i)
                answer += x.first;
        }
        return answer;
    }
};

// bucker sort O(N)
class Solution_1 {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counterData;
        for (const auto& x : s)
            counterData[x]++;
        int maxFreq = 0;
        for (const auto& x : counterData)
            maxFreq = max(maxFreq, x.second);
        vector<vector<char>> lettersCounter(maxFreq);
        for (const auto& x : counterData)
            lettersCounter[x.second - 1].push_back(x.first);
        string answer = "";
        for (int i = maxFreq - 1; i >= 0; --i) {
            if (!lettersCounter[i].empty()) {
                for (const char c : lettersCounter[i]) {
                    for (int j = 0; j <= i; ++j)
                        answer += c;
                }
            }
        }
        return answer;
    }
};

