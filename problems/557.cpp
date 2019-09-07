string reverseWords(string s) {
    int startWordPos = 0;
    int endWordPos = -1;
    int delta = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != ' ') {
            endWordPos++;
        }
        else {
            delta = (endWordPos - startWordPos + 1) / 2;
            for (int j = 0; j < delta; j++) {
                swap(s[startWordPos + j], s[endWordPos - j]);
            }
            startWordPos = i + 1;
            endWordPos = i;
        }
    }
    delta = (endWordPos - startWordPos + 1) / 2;
    for (int j = 0; j < delta; j++) {
        swap(s[startWordPos + j], s[endWordPos - j]);
    }
    return s;
}