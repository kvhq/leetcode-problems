// Number: 49
// Name: Group Anagrams
// Tags: string, hash map

// ugly solution (without sort)

string getDict(const string& s) {
    map<char, int> d;
    for(const auto& x : s) {
        if(d.find(x) != d.end()) {
            d[x]++;
        } else d[x] = 1;
    }
    string id_string;
    for (const auto& x : d) {
        id_string += x.first;
        id_string += x.second;
    }
    return id_string;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> answer;
    unordered_map<string, vector<string>> bigDict;
    for (const auto& x : strs) {
        string d = getDict(x);
        if (bigDict.find(d) != bigDict.end()) bigDict[d].push_back(x);
        else {
            vector<string> vs;
            vs.push_back(x);
            bigDict[d] = vs;
        }
    }
    for (const auto& p : bigDict) {
        answer.push_back(p.second);
    }
    return answer;
}

// with sort

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
