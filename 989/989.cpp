vector<int> addToArrayForm(vector<int>& A, int K) {
    vector<int> answer;
    for (int i = A.size() - 1; i >= 0; --i) {
        K += A[i];
        int temp = K % 10;
        answer.push_back(temp);
        K /= 10;
    }
    while (K != 0) {
        int temp = K % 10;
        answer.push_back(temp);
        K /= 10;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}