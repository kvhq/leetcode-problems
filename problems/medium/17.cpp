// Number: 17
// Name: Letter Combinations of a Phone Number
// Tags: DP

// recursion; time O(4ˆN * N) space O(N)
class Solution_1 {
public:
    void helper(string s, int i, string digits, unordered_map<char, vector<char>> dict, vector<string>& answer) {
        if (i == digits.size()) answer.push_back(s);
        else
            for (const auto& x : dict[digits[i]])
                helper(s + x, i + 1, digits, dict, answer);
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> dict;
        dict['2'] = {'a', 'b', 'c'};
        dict['3'] = {'d', 'e', 'f'};
        dict['4'] = {'g', 'h', 'i'};
        dict['5'] = {'j', 'k', 'l'};
        dict['6'] = {'m', 'n', 'o'};
        dict['7'] = {'p', 'q', 'r', 's'};
        dict['8'] = {'t', 'u', 'v'};
        dict['9'] = {'w', 'x', 'y', 'z'};
        if (digits == "") return {};
        vector<string> answer;
        string temp;
        helper(temp, 0, digits, dict, answer);
        return answer;
    }
};

// iterative
class Solution_2 {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> dict;
        dict['2'] = {'a', 'b', 'c'};
        dict['3'] = {'d', 'e', 'f'};
        dict['4'] = {'g', 'h', 'i'};
        dict['5'] = {'j', 'k', 'l'};
        dict['6'] = {'m', 'n', 'o'};
        dict['7'] = {'p', 'q', 'r', 's'};
        dict['8'] = {'t', 'u', 'v'};
        dict['9'] = {'w', 'x', 'y', 'z'};
        if (digits == "") return {};
        vector<string> answer;
        stack<string> st;
        st.push("");
        while (!st.empty()) {
            string current = st.top();
            st.pop();
            if (current.size() == digits.size()) answer.push_back(current);
            else {
                int currentIndex = current.size();
                for (const auto& x : dict[digits[currentIndex]])
                    st.push(current + x);
            }
        }
        
        return answer;
    }
};

