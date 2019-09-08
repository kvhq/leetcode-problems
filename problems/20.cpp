bool isValid(string s) {
    stack<char> myStack;
    for (const auto& x : s) {
        if (x == '(' || x == '[' || x == '{') {
            myStack.push(x);
        }
        else if (myStack.empty()) {
            return false;
        }
        if (x == ')') {
            char temp = myStack.top();
            if (temp == '(') {
                myStack.pop();
            }
            else return false;
        }
        if (x == ']') {
            char temp = myStack.top();
            if (temp == '[') {
                myStack.pop();
            }
            else return false;
        }
        if (x == '}') {
            char temp = myStack.top();
            if (temp == '{') {
                myStack.pop();
            }
            else return false;
        }
    }
    if (myStack.empty()) {
        return true;
    }
    else return false;
}