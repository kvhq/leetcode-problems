// Number: 244
// Name: Shortest Word Distance II
// Tags: array

class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < (int)wordsDict.size(); ++i) {
            if (d_data.find(wordsDict[i]) != d_data.end())
                d_data[wordsDict[i]].push_back(i);
            else d_data[wordsDict[i]] = {i};
        }
    }

    int shortest(string word1, string word2) {
        vector<int>& v_word1 = d_data[word1];
        vector<int>& v_word2 = d_data[word2];
        int answer = -1;
        for (const auto& x : v_word1) {
            for (const auto& y : v_word2) {
                int temp = abs(x - y);
                if (answer == -1) answer = temp;
                else if (answer > temp) answer = temp;
            }
        }
        return answer;
    }
private:
    unordered_map<string, vector<int>> d_data;
};

