// Number: 953
// Name: Verifying an Alien Dictionary
// Tags: string

bool compareLetters(char c1, char c2, const string& order) {
    int i1 = 0;
    int i2 = 0;
    for (int i = 0; i < order.size(); ++i) {
        if (order[i] == c1) i1 = i;
        else if (order[i] == c2) i2 = i;
    }
    return i1 < i2;
}

bool compareWords(const string& w1, const string& w2, const string& order) {
    size_t i1 = 0;
    size_t i2 = 0;
    while (i1 < w1.size() && i2 < w2.size()) {
        if (w1[i1] == w2[i2]) {
            i1++;
            i2++;
        } else return compareLetters(w1[i1], w2[i2], order);
    }
    if (w1.size() < w2.size()) return true;
    return false;
}

bool isAlienSorted(vector<string>& words, string order) {
    if (words.size() <= 1) return true;
    for(size_t i = 0; i < words.size() - 1; ++i) {
        if (!compareWords(words[i], words[i + 1], order)) return false;
    }
    return true;
}

