vector<int> diStringMatch(string S) {
    vector<int> answer;
    int maxS = S.size();
    int lowS = 0;
    for (const auto& x : S) {
        if (x == 'D') {
            answer.push_back(maxS--);
        }
        if (x == 'I') {
            answer.push_back(lowS++);
        }
    }
    answer.push_back(lowS);
    return answer;
}
