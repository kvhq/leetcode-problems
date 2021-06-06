// Number: 49
// Name: Group Anagrams
// Tags: string, hash map

// without sort, coding key
class Solution_0 {
public:
    string makeKey(const string& s) {
        vector<int> v(26, 0);
        for (const auto& c : s)
            v[c - 'a'] += 1;
        string key;
        for (const auto& x : v)
            key += ('0' + x) + '#';
        return key;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> data;
        for (const auto& s : strs) {
            string key = makeKey(s);
            data[key].push_back(s);
        }
        vector<vector<string>> answer;
        for (const auto& x : data) answer.push_back(x.second);
        return answer;
    }
};


// with sort O(N * log K) O(N * K)

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> answer;
    unordered_map<string, vector<string>> bigDict;
    for (auto x : strs) {
        string d = x;
        sort(d.begin(), d.end());
        bigDict[d].push_back(x);
    }
    for (const auto& p : bigDict) {
        answer.push_back(p.second);
    }
    return answer;
}
