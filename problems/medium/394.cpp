// Number: 394
// Name: Decode String
// Tags: stack, string

// one stack, time O(K*K*K*K...*K*maxN) space same
class Solution_0 {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ']') st.push(s[i]);
            else {
                string curString;
                while (st.top() != '[') {
                    curString = st.top() + curString;
                    st.pop();
                }
                st.pop();
                string curK;
                while (!st.empty() && isdigit(st.top())) {
                    curK = st.top() + curK;
                    st.pop();
                }
                int k = stoi(curK);
                for (int j = 0; j < k; ++j)
                    for (const auto& x : curString)
                        st.push(x);
            }
        }
        string answer;
        while (!st.empty()) {
            answer = st.top() + answer;
            st.pop();
        }
        return answer;
    }
};

// two stacks, time O(maxK*n) space (m+n) where m - number of digits, n - chars
class Solution_1 {
public:
    string decodeString(string s) {
        stack<string> stringStack;
        stack<int> kStack;
        int k = 0;
        string curString;
        for (const auto& x : s) {
            if (isdigit(x))
                k = k * 10 + (x - '0');
            else if (x == '[') {
                kStack.push(k);
                stringStack.push(curString);
                curString = "";
                k = 0;
            } else if (x == ']') {
                string decodedString = stringStack.top();
                for (int i = 0; i < kStack.top(); ++i) {
                    decodedString += curString;
                }
                stringStack.pop();
                kStack.pop();
                curString = decodedString;
            } else curString += x;
        }
        return curString;
    }
};

