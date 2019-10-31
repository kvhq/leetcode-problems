int maxNumberOfBalloons(string text) {
    if (text.length() == 0) {
        return 0;
    }
    unordered_map<char,int> freqChars;
    freqChars['b'] = 0;
    freqChars['a'] = 0;
    freqChars['l'] = 0;
    freqChars['o'] = 0;
    freqChars['n'] = 0;
    for (const auto& x : text) {
        if (x == 'b' ||
            x == 'a' ||
            x == 'l' ||
            x == 'o' ||
            x == 'n') {
            freqChars[x]++;
        }
    }
    freqChars['l'] /= 2;
    freqChars['o'] /= 2;
    int answer = 10000;
    for (const auto& x : freqChars) {
        if (x.second < answer) {
            answer = x.second;
        }
    }
    return answer;
}
