int minAddToMakeValid(string S) {
    stack<char> myStack;
    for (const auto& x : S) {
        if (myStack.empty()) {
            myStack.push(x);
        }
        else {
            char tempC = myStack.top();
            if (x == ')' && tempC == '(') {
                myStack.pop();
            }
            else {
                myStack.push(x);
            }
        }
    }
    return myStack.size();
}