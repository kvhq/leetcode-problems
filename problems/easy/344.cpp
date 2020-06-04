// Number: 344
// Name: Reverse String
// Tags: string

void reverseString(vector<char>& s) {
    for (int i = 0; i < (int)s.size() / 2; ++i) {
        swap(s[i], s[(int)s.size() - 1 - i]);
    }
}

