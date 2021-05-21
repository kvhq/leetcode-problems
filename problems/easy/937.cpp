// Number: 937
// Name: Reorder Data in Log Files
// Tags: sorting

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        int digitsStartIndex = logs.size() - 1;
        for (int i = logs.size() - 1; i >= 0;) {
            string curStr = logs[i];
            if (!isalpha(curStr[curStr.size() - 1])) {
                swap(logs[i--], logs[digitsStartIndex--]);
            } else i--;
        }
        sort(logs.begin(), logs.begin() + ++digitsStartIndex, [](const auto& lhs, const auto& rhs) {
            int lhsSpaceIndex = 0;
            int rhsSpaceIndex = 0;
            for (int i = 0; i < lhs.size(); ++i) {
                if (lhs[i] == ' ') {
                    lhsSpaceIndex = i;
                    break;
                }
            }
            for (int i = 0; i < rhs.size(); ++i) {
                if (rhs[i] == ' ') {
                    rhsSpaceIndex = i;
                    break;
                }
            }
            if (lhs.substr(lhsSpaceIndex) == rhs.substr(rhsSpaceIndex))
                return lhs.substr(0, lhsSpaceIndex) < rhs.substr(0, rhsSpaceIndex);
            else return lhs.substr(lhsSpaceIndex + 1) < rhs.substr(rhsSpaceIndex + 1);
        });
        return logs;
    }
};

