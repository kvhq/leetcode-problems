int getQueenPosFromString(const string& s) {
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == 'Q') return i;
    }
    return -1;
}

bool checkVariant(const vector<string>& variant) {
    size_t varSize = variant.size();
    int curPos = getQueenPosFromString(variant[varSize - 1]);
    for (size_t i = 0; i < varSize - 1; ++i) {
        int diff = abs(getQueenPosFromString(variant[i]) - curPos);
        if (diff == 0 || diff == varSize - 1 - i) {
            return false;
        }
    }
    return true;
}

void findQueens(const int& n, const int& row, 
                vector<string>& var, vector<vector<string>>& ans) {
    if (row == n) {
        ans.push_back(var);
    } else {
        for (int col = 0; col < n; ++col) {
            string varRow(n, '.');
            varRow[col] = 'Q';
            var.push_back(varRow);
            if (checkVariant(var)) {
                findQueens(n, row + 1, var, ans);
            }
            var.pop_back();
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> answer;
    vector<string> tempVariant;
    findQueens(n, 0, tempVariant, answer);
    return answer;
}
