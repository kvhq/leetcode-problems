//Number: 1002
//Name: Find Common Characters
//Tags: array, hash map

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        unordered_map<char, int> data;
        vector<string> answer;
        for (const auto& x : A[0]) {
            if (data.find(x) != data.end()) data[x]++;
            else data[x] = 1;
        }
        if (A.size() == 1) {
            for (const auto& x : data) {
                for (int i = 0; i < x.second; ++i) {
                    string s(1, x.first);
                    answer.push_back(s);
                }
            }
            return answer;
        }
        for (size_t i = 1; i < A.size(); ++i) {
            unordered_map<char, int> temp_data;
            for (const auto& x : A[i]) {
                if (temp_data.find(x) != temp_data.end()) temp_data[x]++;
                else temp_data[x] = 1;
            }
            for (auto& x : data) {
                if (temp_data.find(x.first) != temp_data.end()) {
                    if (temp_data[x.first] < data[x.first]) data[x.first] = temp_data[x.first];
                } else data[x.first] = 0;
            }
        }
        for (const auto& x : data) {
            for (int i = 0; i < x.second; ++i) {
                string s(1, x.first);
                answer.push_back(s);
            }
        }
        return answer;
    }
};

