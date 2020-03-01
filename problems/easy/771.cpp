// hash table

int numJewelsInStones(string J, string S) {
    unordered_set<char> jewels;
    int answer = 0;
    for (const auto& x : J) {
        jewels.insert(x);
    }
    for (const auto& x : S) {
        if (jewels.count(x) > 0) {
            answer++;
        }
    }
    return answer;
}
