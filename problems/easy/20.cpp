//Number: 20
//Name: Valid Parentheses
//Tags: stack

class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        stack<char> st;
        for (const auto& x : s) {
            if (x == '(' || x == '{' || x == '[') st.push(x);
            else if (st.empty()) return false;
            else if (x == ')') {
                if (st.top() != '(') return false;
                st.pop();
            } else if (x == '}') {
                if (st.top() != '{') return false;
                st.pop();
            } else if (x == ']') {
                if (st.top() != '[') return false;
                st.pop();
            }
        }
        if (st.empty()) return true;
        return false;
    }
};

