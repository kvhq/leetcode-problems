// Number: 760
// Name: Find Anagram Mappings
// Tags: Hash map

vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
    if (!A.size()) return {0};
    unordered_map<int,int> startDict;
    for (int i = 0; i < B.size(); ++i) startDict[B[i]] = i;
    vector<int> answer;
    for (int i = 0; i < A.size(); ++i) answer.push_back(startDict[A[i]]);
    return answer;
}

