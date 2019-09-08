#include <string>
#include <stack>
#include <iostream>

using namespace std;

string remoteOuter(string S) {
    stack<char> myStack;
    string answer;
    int flag = 0;
    for (const auto& x : S) {
        if (myStack.empty()) {
            myStack.push(x);
            continue;
        }
        if (x == '(') {
            flag++;
            myStack.push(x);
            answer += x;
        }
        if (x == ')') {
            if (flag == 0) {
                myStack.pop();
            }
            else {
                answer += x;
                myStack.pop();
                flag--;
            }
        }
    }
    return answer;
}

int main() {
    string S;
    cout << "Please, enter your string: " << endl;
    cin >> S;

    cout << remoteOuter(S) << endl;
    return 0;
}