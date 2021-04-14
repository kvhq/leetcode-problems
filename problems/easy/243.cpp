// Number: 243
// Name: Shortest Word Distance
// Tags: array

int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
    int answer = -1;
    int cur_word1 = -1;
    int cur_word2 = -1;
    for (int i = 0; i < (int)wordsDict.size(); ++i) {
        if (wordsDict[i] == word1) cur_word1 = i;
        if (wordsDict[i] == word2) cur_word2 = i;
        if (cur_word1 != -1 && cur_word2 != -1) {
            int cur_distance = abs(cur_word1 - cur_word2);
            if (answer == -1 || answer > cur_distance) answer = cur_distance;
        }
    }
    return answer;
}

