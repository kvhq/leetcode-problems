void fillKeywordMap(unordered_map<char,int>& keyboardMap, const string& row, int rowNumber) 
{
    for (const auto& letter : row) {
        keyboardMap[letter] = rowNumber;
    }
}

vector<string> findWords(vector<string>& words) {
    string firstRow = "QWERTYUIOPqwertyuiop";
    string secondRow = "ASDFGHJKLasdfghjkl";
    string thirdRow = "ZXCVBNMzxcvbnm";
    unordered_map<char, int> keyboard;
    fillKeywordMap(keyboard, firstRow, 1);
    fillKeywordMap(keyboard, secondRow, 2);
    fillKeywordMap(keyboard, thirdRow, 3);
    vector<string> answer;
    for (const auto& word : words) {
        int curCode = keyboard[word[0]];
        for (const auto& letter : word) {
            if (keyboard[letter] != curCode) {
                curCode = -1;
                break;
            }
        }
        if (curCode != -1) {
            answer.push_back(word);
        }
    }
    return answer;
}
