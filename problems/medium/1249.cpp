// Number: 1249
// Name: Minimum Remove to Make Valid Parentheses
// Tags: array, string

string minRemoveToMakeValid(string s) {
    stack<int> data;
    vector<int> to_delete = {};
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == ')') {
            if (data.empty()) to_delete.push_back(i);
            else data.pop();
        } else if (s[i] == '(') data.push(i);
    }
    for (const auto& x : to_delete) {
        s[x] = '-';
    }
    while (!data.empty()) {
        s[data.top()] = '-';
        data.pop();
    }
    string answer;
    for (const auto& x : s) {
        if (x != '-') answer.push_back(x);
    }
    return answer;
}

