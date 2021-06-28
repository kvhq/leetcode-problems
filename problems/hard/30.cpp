// Number: 30
// Name: Substring with Concatenation of All Words
// Tags: sliding window, string

// O(N*M) solution, ugly
class Solution_0 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // read by word chunks of words[0].size()
        // if it is in words then start check for this index ...
        // as soon as we fail -> continue with ++index
        
        // ... speaking about the check
        // we dismiss this word from words and try to find next chunk in words
        // if we success - we dismiss this word and continue with next chunk
        // as soon as we make words empty (and without duplications check) - success and push_back index
        // if we fail somewhere - stop check process and return
        int chunkSize = words[0].size();
        unordered_map<string, int> vocab_data;
        int totalSize = 0;
        for (const auto& x : words) {
            vocab_data[x]++;
            totalSize += x.size();
        }
        vector<int> answer;
        for (int i = 0; i < s.size(); ++i) {
            if (i + totalSize > s.size()) break;
            string curStr = s.substr(i, chunkSize);
            if (vocab_data.find(curStr) != vocab_data.end()) {
                unordered_map<string, int> window_data;
                window_data[curStr]++;
                if (vocab_data == window_data) {
                    answer.push_back(i);
                    continue;
                }
                int curIndex = i + chunkSize;
                while (curIndex < s.size()) {
                    curStr = s.substr(curIndex, chunkSize);
                    curIndex += chunkSize;
                    if (vocab_data.find(curStr) != vocab_data.end())
                        window_data[curStr]++;
                    else break;
                    if (window_data[curStr] > vocab_data[curStr]) break;
                    if (vocab_data == window_data) {
                        answer.push_back(i);
                        break;
                    }
                }
                // we found possible start
            }
            // if not - just continue
        }
        return answer;
    }
};



