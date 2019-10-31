string removeDuplicates(string S) {
    stack<char> tempStack;
    for(const auto& x : S) {
        if (tempStack.empty()) {
            tempStack.push(x);
        } else if (tempStack.top() == x) {
            tempStack.pop();
        } else {
            tempStack.push(x);
        }
    }
    string answer;
    while (!tempStack.empty()) {
        answer += tempStack.top();
        tempStack.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
