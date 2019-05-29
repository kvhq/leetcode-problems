int uniqueMorseRepresentations(vector<string>& words) {
    map<char, string> vocabulary;
    vocabulary['a'] = ".-";
    vocabulary['b'] = "-...";
    vocabulary['c'] = "-.-.";
    vocabulary['d'] = "-..";
    vocabulary['e'] = ".";
    vocabulary['f'] = "..-.";
    vocabulary['g'] = "--.";
    vocabulary['h'] = "....";
    vocabulary['i'] = "..";
    vocabulary['j'] = ".---";
    vocabulary['k'] = "-.-";
    vocabulary['l'] = ".-..";
    vocabulary['m'] = "--";
    vocabulary['n'] = "-.";
    vocabulary['o'] = "---";
    vocabulary['p'] = ".--.";
    vocabulary['q'] = "--.-";
    vocabulary['r'] = ".-.";
    vocabulary['s'] = "...";
    vocabulary['t'] = "-";
    vocabulary['u'] = "..-";
    vocabulary['v'] = "...-";
    vocabulary['w'] = ".--";
    vocabulary['x'] = "-..-";
    vocabulary['y'] = "-.--";
    vocabulary['z'] = "--..";
    unordered_set<string> newWords;
    for (const auto& x : words) {
        string temp;
        for (const auto& c : x) {
            temp += vocabulary[c];
        }
        newWords.insert(temp);
    }
    return newWords.size();
}