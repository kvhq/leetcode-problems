bool backspaceCompare(string S, string T) {
    int a1Size = S.size();
    int a2Size = T.size();
    int a1Flag = 0;
    int a2Flag = 0;
    int i = a1Size - 1;
    int j = a2Size - 1;
    while (i >= 0 || j >= 0) {
        if (i >= 0) {
            if (S[i] == '#') {
                a1Flag++;
                i--;
                continue;
            }
            else if (a1Flag > 0) {
                a1Flag--;
                i--;
                continue;
            }
        }
        if (j >= 0) {
            if (T[j] == '#') {
                a2Flag++;
                j--;
                continue;
            }
            else if (a2Flag > 0) {
                a2Flag--;
                j--;
                continue;
            }
        }
        if (i >= 0 && j < 0) return false;
        if (i < 0 && j >= 0) return false;
        if (S[i] != T[j]) return false;
        if (i >= 0) i--;
        if (j >= 0) j--;
    }
    if (i != j) return false;
    return true;
}