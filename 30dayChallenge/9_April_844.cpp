// Number: 844
// Name: Backspace String Compare
// Tag: string, two pointer

// O(1) space
bool backspaceCompare(string S, string T) {
    int s_i = (int)S.size() - 1;
    int t_i = (int)T.size() - 1;
    int s_back_num = 0;
    int t_back_num = 0;
    while (true) {
        // find first letter in S
        while (s_i > -1) {
            if (S[s_i] == '#') {
                s_i--;
                s_back_num++;
            } else if (s_back_num > 0) {
                s_back_num--;
                s_i--;
            } else break;
        }
        // find first letter in T
        while (t_i > -1) {
            if (T[t_i] == '#') {
                t_i--;
                t_back_num++;
            } else if (t_back_num > 0) {
                t_back_num--;
                t_i--;
            } else break;
        }
        if (t_i < 0 && s_i < 0) return true;
        else if (t_i > -1 && s_i > -1) {
            if (S[s_i] == T[t_i]) {
                s_i--;
                t_i--;
            } else return false;
        } else return false;
    }
    return false;
}

// O(n) space
bool backspaceCompare(string S, string T) {
    stack<char> finalS;
    stack<char> finalT;
    for (int i = 0; i < (int)S.size(); ++i) {
        if (S[i] != '#') finalS.push(S[i]);
        else if (finalS.size() != 0) finalS.pop();
    }
    for (int i = 0; i < (int)T.size(); ++i) {
        if (T[i] != '#') finalT.push(T[i]);
        else if (finalT.size() != 0) finalT.pop();
    }
    if (finalS == finalT) return true;
    return false;
}
