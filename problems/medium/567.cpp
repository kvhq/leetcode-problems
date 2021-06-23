// Number: 567
// Name: Permutation in String
// Tags: sliding window

class Solution {
public:
    bool isMatching(const vector<int>& m1, const vector<int>& m2) {
        if (m1 != m2) return false;
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> s1_data(26);
        vector<int> window_data(26);
        for (int i = 0; i < s1.size(); ++i) {
            s1_data[s1[i] - 'a']++;
            window_data[s2[i] - 'a']++;
        }
        for (int i = 0; i < s2.size() - s1.size(); ++i) {
            if (isMatching(s1_data, window_data)) return true;
            window_data[s2[i + s1.size()] - 'a']++;
            window_data[s2[i] - 'a']--;
        }
        return isMatching(s1_data, window_data);
    }
};


