// Number: 1209
// Name: Remove All Adjacent Duplicates in String II
// Tags: stack

// ugly one
class Solution_1 {
public:
    string removeDuplicates(string s, int k) {
        stack<char> data;
        string cache = "";
        string answer;
        for (size_t i = 0; i < s.size();) {
            if (cache.empty()) {
                if (data.empty()) cache += s[i];
                else if (data.top() == s[i]) {
                    cache += s[i];
                    cache += data.top();
                    data.pop();
                    while (!data.empty() && data.top() == cache[0]) {
                        cache += data.top();
                        data.pop();
                    }
                    if (cache.size() == k) cache = "";
                } else cache += s[i];
                i++;
            }
            else if (s[i] == cache[0]) {
                if (cache.size() == k - 1) cache = "";
                else cache += s[i];
                i++;
            } else {
                for (const auto& x : cache) data.push(x);
                cache = s[i];
                i++;
            }
        }
        while (!data.empty()) {
            answer += data.top();
            data.pop();
        }
        reverse(answer.begin(), answer.end());
        answer += cache;
        return answer;
    }
};

// stack count
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int> data;
        for (size_t i = 0; i < s.size(); ++i) {
            if (data.empty() || s[i] != s[i - 1]) data.push(1);
            else if (++data.top() == k) {
                data.pop();
                s.erase(i - k + 1, k);
                i = i - k;
            }
        }
        return s;
    }
};

