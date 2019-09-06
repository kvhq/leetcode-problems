vector<int> partitionLabels(string S) {
    if (S.length() == 1) {
        return {1};
    }
    vector<int> answer;
    unordered_map<char,int> freqMap;
    for (int i = 0; i < S.length(); i++) {
        freqMap[S[i]] = i;
    }
    int start = 0;
    int max = freqMap[S[0]];
    for (int i = 0; i < S.length(); i++) {
        if (i == max) {
            answer.push_back(max - start + 1);
            start = i + 1;
            max = freqMap[S[start]];
        }
        else if (freqMap[S[i]] > max) {
            max = freqMap[S[i]];
        }
    }
    return answer;
}
