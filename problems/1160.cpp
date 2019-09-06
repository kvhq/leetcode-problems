bool isWordGood(const string& inputString, unordered_map<char, int> vocabulary) {
    for (const char& ch : inputString) {
        vocabulary[ch]--;
        if (vocabulary[ch] < 0) {
            return false;
        }
    }
    return true;
}

int countCharacters(vector<string>& words, string chars) {
    int resultLength = 0;
    unordered_map<char, int> vocabulary;
    for (const auto& ch : chars) {
        vocabulary[ch]++;
    }
    for (const auto& word : words) {
        if (isWordGood(word, vocabulary)) {
            resultLength += word.length();
        }
    }
    return resultLength;
}
