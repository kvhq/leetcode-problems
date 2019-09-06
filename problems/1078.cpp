vector<string> findOcurrences(string text, string first, string second) {
    int firstFlag = 0;
    int secondFlag = 0;
    vector<string> answer;
    vector<string> myText;
    string word = "";
    for (const auto& x : text) {
        if (x == ' ') {
            myText.push_back(word);
            word = "";
        }
        else word += x;
    }
    if (word != "") myText.push_back(word);
    for (auto x : myText) {
        if (firstFlag && secondFlag) {
            answer.push_back(x);
            firstFlag = 0;
            secondFlag = 0;
        }
        if (firstFlag == 0) {
            if (x == first) {
                firstFlag = 1;
            }
        }
        else if (x == second) {
            secondFlag = 1;
        }
        else if (x != first) {
            firstFlag = 0;
        }
    }
    return answer;
}