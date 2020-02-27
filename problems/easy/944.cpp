// greedy

int minDeletionSize(vector<string>& A) {
    // we go through each column and check for non-decrease type
    // if we see false, skip the rest of the column and increase the answer by 1
    int N = A.size();
    if (N == 0 || N == 1) {
        return 0;
    }
    int s = A[0].size();
    if (s == 0) {
        return 0;
    }
    int answer = 0;
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < N - 1; ++j) {
            if (A[j][i] > A[j + 1][i]) {
                answer++;
                break;
            }
        }
    }
    return answer;
}
