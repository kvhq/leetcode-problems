// Number: 249
// Name: Group Shifted Strings
// Tags: strings

class Solution_1 {
public:
    bool compareWords(const string& i_word1, const string& i_word2) {
        int temp = -1;
        for (int i = 0; i < (int)i_word1.size(); ++i) {
            int k = int(i_word2[i]) - int(i_word1[i]);
            if (k < 0) k +=26;
            if (temp == -1) temp = k;
            else if (temp != k)
                return false;
        }
        return true;
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> answer = {{}};
        for (const auto& x : strings) {
            bool wasInserted = false;
            for (auto& grouped : answer) {
                if (grouped.empty()) {
                    grouped.push_back(x);
                    wasInserted = true;
                    break;
                }
                if (x.size() == grouped[0].size()) {
                    if (compareWords(x, grouped[0])) {
                        grouped.push_back(x);
                        wasInserted = true;
                        break;
                    }
                }
            }
            if (!wasInserted) answer.push_back({x});
        }
        return answer;
    }
};

class Solution_2 {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> data;
        string key;
        
        for (const auto& x : strings) {
            key = "";
            char firstChar = x[0];
            for (const auto& c : x) {
                int diff = firstChar - c;
                if (diff < 0) diff += 26;
                key += diff + ' ';
            }
            
            data[key].push_back(x);
        }
        
        vector<vector<string>> answer;
        
        for (auto it = data.begin(); it != data.end(); it++) {
            answer.push_back(it->second);
        }
        return answer;
        
    }
};

