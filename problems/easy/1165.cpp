// Number: 1165
// Name: Single-Row Keyboard
// Tags: string

// solution for different languages

class Solution_1 {
public:
    int printLetter( const char letter, char& pos) {
        int ans = abs(pos - letter);
        cout << ans << endl;
        pos = letter;
        return ans;
    }
    
    int calculateTime(string keyboard, string word) {
        map<char, int> keyboardDict;
        for (int i = 0; i < keyboard.size(); ++i) {
            keyboardDict[keyboard[i]] = i;
        }
        int moves = 0;
        char curPos = keyboard[0];
        for (const auto& l : word) {
            moves += abs(keyboardDict[l] - keyboardDict[curPos]);
            curPos = l;
        }
        return moves;
    }
};

// optimized solution for eng keyboard

class Solution {
public:
    int printLetter(int kb[], const char& letter, int& pos) {
        int ans = abs(kb[abs(letter - 'a')] - pos);
        pos = kb[abs(letter - 'a')];
        return ans;
    }
    
    int calculateTime(string keyboard, string word) {
        int kbmap[26];
        for (int i = 0; i < 26; ++i) {
            kbmap[abs(keyboard[i] - 'a')] = i;
        }
        int moves = 0;
        int curPos = 0;
        for (const auto& x : word) {
            moves += printLetter(kbmap, x, curPos);
        }
        return moves;
    }
};

